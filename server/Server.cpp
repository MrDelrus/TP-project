#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "DataHandler.cpp"

class Server {
private:
    int main_port;
    int number_of_clients_in_listening_queue;
//    query_converter["SIGN_UP"] = 0;
//    query_converter["SIGN_IN"] = 1;
//    query_converter["IS_TUTOR"] = 2;
//    query_converter["GET_GROUPS"] = 3;
//    query_converter["ADD_GROUP"] = 4;
//    query_converter["ENTER_GROUP"] = 5;
//    query_converter["GET_STUDENTS_IN_GROUP"] = 6;
//    query_converter["GET_TASKS"] = 7;
//    query_converter["ADD_TASK"] = 8;
//    query_converter["ADD_STUDENT_IN_GROUP"] = 9;
//    query_converter["GET_TASK_TEXT"] = 10;
//    query_converter["GET_LAST_5_MESSAGES"] = 11;
//    query_converter["SEND_MESSAGE"] = 12;

    static bool check_if_person_exists(const std::string& name) {
        if (Data::name_to_person.count(name) == 0) {
            return false;
        }
        return true;
    }

    static bool check_if_person_exists_and_is_tutor(const std::string& name) {
        if (check_if_person_exists(name) && Data::name_to_person[name].get_role() == type::tutor) {
            return true;
        }
        return false;
    }

    static std::string answer_to_query(std::map<std::string, int>& map_to_switch, const std::vector<std::string>& query) {
        int switch_int = map_to_switch[query[0]];
        switch (switch_int) {
            case 0: {
                if (Data::name_to_person.count(query[2]) == 0) {
                    return "False";
                }
                Person person_to_add = Person(query[2], query[3], query[1] == "tutor" ? type::tutor : type::student);
                Data::name_to_person[query[2]] = person_to_add;
                return "True";
            }
            case 1: {
                if (!Data::name_to_person[query[1]].check_password(query[2])) {
                    return "False";
                }
                return "True";
            }
            case 2: {
                if (check_if_person_exists_and_is_tutor(query[1])) {
                    return "True";
                }
                return "False";
            }
            case 3: {
                if (!check_if_person_exists(query[1])) {
                    return "False";
                }
                return Data::name_to_person[query[1]].get_groups();
            }
            case 4: {
                if (!check_if_person_exists_and_is_tutor(query[1])) {
                    return "False";
                }
                Data::name_to_person[query[1]].add_group(query[2]);
                return "True";
            }
            case 5: {

            }
            case 6: {
                if (!check_if_person_exists_and_is_tutor(query[1])) {
                    return "False";
                }
                return Data::name_to_group[query[2]].get_students_names();
            }
            case 7: {
                if (!check_if_person_exists(query[1])) {
                    return "False";
                }
                return Data::name_to_group[query[2]].get_tasks_names();
            }
            case 8: {
                if (!check_if_person_exists_and_is_tutor(query[1])) {
                    return "False";
                }
                //TODO: Data::name_to_group[query[2]].add_task();
                return "True";
            }
            case 9: {
                if (!check_if_person_exists_and_is_tutor(query[1])) {
                    return "False";
                }
                Data::name_to_group[query[2]].add_student(query[3]);
                return "True";
            }
            case 10: {
                if (!check_if_person_exists(query[1])) {
                    return "False";
                }
                return Data::name_to_group[query[2]].set_tasks()[query[3]].get_problem_text();
            }
            case 11: {
                if (!check_if_person_exists(query[1])) {
                    return "False";
                }
                //TODO: complete this
            }
            case 12: {
                if (!check_if_person_exists(query[1])) {
                    return "False";
                }
                Data::name_to_group[query[2]].get_task(query[3])->get_discussion()->add_message(query[4], query[1]);
                return "True";
            }
        }
        return "False";
    }
public:
    Server(int main_port_c, int number_of_clients_in_listening_queue_c) {
        main_port = main_port_c;
        number_of_clients_in_listening_queue = number_of_clients_in_listening_queue_c;
    }
    Server(const Server& to_copy) = delete;
    ~Server() = default;
    Server& operator = (const Server& to_copy) = delete;
    void run() const {
        int main_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (main_socket_fd < 0) {
            throw std::runtime_error("ERROR, couldn't create socket!");
        }
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(main_port);
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        int bind_checker = bind(main_socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        if (bind_checker < 0) {
            throw std::runtime_error("ERROR, couldn't bind the socket!");
        }
        listen(main_socket_fd, 5);
        struct sockaddr_in cli_addr;
        socklen_t client_length = sizeof(cli_addr);
        int client_socket = accept(main_socket_fd, (struct sockaddr*)&cli_addr, &client_length);
        if (client_socket < 0) {
            throw std::runtime_error("ERROR, couldn't accept");
        }
        //TODO: while loop
        char buffer[256];
        int correctness_checker = 0;
        int corr_checker2 = 0;
        while (true) {
            correctness_checker = read(client_socket, buffer, 3 - 1);
            if (correctness_checker < 0) {
                std::cout << "Something went wrong in reading info\n";
                break;
            }
            char number_c[3];
            number_c[0] = buffer[0];
            number_c[1] = buffer[1];
            number_c[2] = buffer[2];
            std::string number_s = static_cast<std::string>(number_c);
            int number_of_chars = std::stoi(number_s);
            corr_checker2 = read(client_socket, buffer, number_of_chars - 1);
            if (corr_checker2 < 0) {
                std::cout << "Something went wrong in reading info\n";
                break;
            }
            std::vector<std::string> fields;
            std::string current_string;
            for (int i = 0; i < number_of_chars; ++i) {
                if (buffer[i] == '#') {
                    if (!current_string.empty()) {
                        fields.push_back(current_string);
                    }
                    current_string = "";
                    continue;
                }
                current_string += buffer[i];
            }
            std::map<std::string, int> query_converter;
            query_converter["SIGN_UP"] = 0;
            query_converter["SIGN_IN"] = 1;
            query_converter["IS_TUTOR"] = 2;
            query_converter["GET_GROUPS"] = 3;
            query_converter["ADD_GROUP"] = 4;
            query_converter["ENTER_GROUP"] = 5;
            query_converter["GET_STUDENTS_IN_GROUP"] = 6;
            query_converter["GET_TASKS"] = 7;
            query_converter["ADD_TASK"] = 8;
            query_converter["ADD_STUDENT_IN_GROUP"] = 9;
            query_converter["GET_TASK_TEXT"] = 10;
            query_converter["GET_LAST_5_MESSAGES"] = 11;
            query_converter["SEND_MESSAGE"] = 12;
            std::string to_send = answer_to_query(query_converter, fields);
            send(client_socket, to_send.c_str(), to_send.size(), 0);
        }
        close(main_socket_fd);
        close(client_socket);
    }
};
