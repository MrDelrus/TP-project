#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Menu.cpp"

using json = nlohmann::json;

// Consequence of actions:
// 1) MessageDataHandler
// 2) ChatDataHandler
// 3) PersonDataHandler
// 4) TaskDataHandler
// 5) GroupDataHandler

class DataHandler {
private:
    json main_json_file;
public:
    [[nodiscard]] json get_json() const {
        return main_json_file;
    }
    json& set_json() {
        return main_json_file;
    }
};

class MessageArrayDataHandler : public DataHandler {
private:
public:
    void add_message_to_json(const Message& message) {
        set_json().push_back({message.messaging_person, message.text});
    }
    std::vector<Message> get_messages() {
        std::vector<Message> answer = std::vector<Message>();
        json current_json = get_json();
        for (auto& i : current_json) {
            answer.emplace_back(i[0], i[1]);
        }
        return answer;
    }
};

class ChatDataHandler {
public:
    static json get_json_from_chat(const Chat& chat) { //chat_name, all_chat, string[] people_in_chat, Message[] messages
        json answer = json();
        answer.push_back(chat.chat_name);
        answer.push_back(chat.get_all_chat());
        answer.push_back(chat.people_in_chat);
        MessageArrayDataHandler helper;
        for (int i = 0; i < chat.get_size(); ++i) {
            helper.add_message_to_json(chat.Get_Message(i));
        }
        answer.push_back(helper.get_json());
        return answer;
    }
    static Chat get_chat_from_json(const json& origin) {
        Chat answer = Chat();
        answer.chat_name = origin[0];
        answer.all_chat = origin[1];
        answer.people_in_chat = std::set<std::string>(origin[2].begin(), origin[2].end());
        MessageArrayDataHandler helper;
        helper.set_json() = origin[3];
        answer.messages = helper.get_messages();
        return answer;
    }
};

class PersonDataHandler {
public:
    static json get_json_from_person(const Person& person) {
        json answer;
        answer.push_back(person.get_name());
        answer.push_back(person.get_password());
        std::string role = person.get_role() == type::student ? "student" : "tutor";
        answer.push_back(role);
        json map_name_group_id;
        for (auto& pair: person.name_to_id_of_groups) {
            map_name_group_id[pair.first] = pair.second;
        }
        answer.push_back(map_name_group_id);
        return answer;
    }
    static Person get_person_from_json(const json& origin) {
        Person answer = Person();
        answer.name = origin[0];
        answer.password = origin[1];
        answer.role = origin[2] == "student" ? type::student : type::tutor;
        for (auto& pair : static_cast<std::map<std::string, long long>>(origin[3])) {
            answer.add_group(pair.first, pair.second);
        }
        return answer;
    }
};

class TaskDataHandler {
public:
    static json get_json_from_task(const Task& task) {
        json answer;
        answer.push_back(task.is_open);
        answer.push_back(task.name);
        answer.push_back(task.problem);
        answer.push_back(task.tutor);
        answer.push_back(task.student);
        answer.push_back(ChatDataHandler::get_json_from_chat(task.discussion));
        return answer;
    }
    static Task get_task_from_json(const json& origin) {
        Task answer = Task();
        answer.is_open = origin[0];
        answer.name = origin[1];
        answer.problem = origin[2];
        answer.tutor = origin[3];
        answer.student = origin[4];
        answer.discussion = ChatDataHandler::get_chat_from_json(origin[5]);
        return answer;
    }
};

class GroupDataHandler {
public:
    static json get_json_from_group(const Group& group) {
        json answer;
        answer.push_back(group.id);
        answer.push_back(group.name);
        answer.push_back(group.tutor_name);
        json student_names;
        for (auto& item : group.students_names) {
            student_names.push_back(item);
        }
        answer.push_back(student_names);
        json tasks;
        for (auto& pair : group.tasks) {
            tasks[pair.first] = TaskDataHandler::get_json_from_task(pair.second);
        }
        answer.push_back(tasks);
        return answer;
    }
    static Group get_group_from_json(json& origin) {
        Group answer = Group();
        answer.id = origin[0];
        answer.name = origin[1];
        answer.tutor_name = origin[2];
        for (auto& item : origin[3]) {
            answer.students_names.insert(item);
        }
        for (json::iterator it = origin[4].begin(); it != origin[4].end(); ++it) {
            answer.tasks[it.key()] = TaskDataHandler::get_task_from_json(it.value());
        }
        return answer;
    }
};



//int main() {
//    json j;
//    j["pi"] = 3.141;
//    std::cout << j["pi"];
//    return 0;
//}
