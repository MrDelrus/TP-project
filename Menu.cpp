// glhf there too
#pragma once
#include "library.h"
#include <iostream>
#include "Person.cpp"
#include "Group.cpp"
#include "Data.cpp"
#include <cstdlib>

class Menu {
private:
    std::string current_string;
    Person* current_person = nullptr;
    Group* current_group = nullptr;
    Task* current_task = nullptr;
    Chat* current_chat = nullptr;


    void Main_menu() {
        int option;
        while (true) {
            std::cout << "You can:\n1) sign in\n2) sign up\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::string client_name, client_password;
                    std::cout << "Enter your name here\n";
                    std::cin >> client_name;
                    std::cout << "Enter your password here\n";
                    std::cin >> client_password;
                    Person* supposed_person = &(Data::name_to_person[client_name]);
                    if (!supposed_person->check_password(client_password))
                    {
                        while (!supposed_person->check_password(client_password))
                        {
                            std::cout << "Try again, name or password is wrong\n";
                            std::cout << "Enter your name here\n";
                            std::cin >> client_name;
                            std::cout << "Enter your password here\n";
                            std::cin >> client_password;
                            supposed_person = &(Data::name_to_person[client_name]);
                        }
                    }
                    current_person = supposed_person;
                    std::string client_role = supposed_person->get_role() == type::student ? "student" : "tutor";
                    current_string = "profile " + client_role;
                    return;
                }
                case 2: {
                    std::cout << "Enter your role here, student or tutor. If you enter something wrong, you will be student\n";
                    std::string client_role, client_name, client_password, second_password;
                    std::cin >> client_role;
                    type real_role = type::student;
                    if (client_role == "tutor")
                    {
                        real_role = type::tutor;
                    }
                    std::cout << "Enter your name here\n";
                    std::cin >> client_name;
                    std::cout << "Enter your password here\n";
                    std::cin >> client_password;
                    std::cout << "Enter your password here once again\n";
                    std::cin >> second_password;
                    if (second_password != client_password)
                    {
                        std::cout << "Error\n";
                        Main_menu();
                        return;
                    }
                    current_person = new Person(client_name, client_password, real_role);
                    current_string = "profile " + client_role;
                    Data::name_to_person[client_name] = *current_person;
                    std::cout << "You have been registered! Now you can use it!";
                    return;
                }
                default: {
                    std::cout << "wrong request\n";
                    break;
                }
            }
        }
    }

    void Profile_menu() {
        int option;
        while (true) {
            std::cout << "You can:\n1) show groups\n2) choose group\n3) add group if you are tutor\n4) back\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << "Groups: \n";
                    std::cout << current_person->get_groups();
                    break;
                }
                case 2: {
                    std::cout << "Enter group name\n";
                    std::string group_name;
                    std::cin >> group_name;
                    current_group = &(Data::id_to_group[current_person->name_to_id_of_groups[group_name]]);
                    std::string client_role = current_person->get_role() == type::student ? "student" : "tutor";
                    current_string = "group " + client_role;
                    return;
                }
                case 3: {
                    if (current_person->get_role() == type::student) {
                        std::cout << "Sorry, you are not a tutor!\n";
                        break;
                    }
                    std::cout << "Enter group's name, number of students and students' names which you want in this group\n";
                    std::string group_name, helper;
                    std::cin >> group_name;
                    int number_of_students;
                    std::cin >> number_of_students;
                    std::set<std::string> students_names = std::set<std::string>();
                    long long id = std::rand();
                    for (int i = 0; i < number_of_students; ++i) {
                        std::cin >> helper;
                        if (Data::name_to_person.find(helper) == Data::name_to_person.end()) {
                            std::cout << "There is no such student in database\n";
                        }
                        else {
                            students_names.insert(helper);
                            Data::name_to_person[helper].add_group(group_name, id);
                        }
                    }
                    current_person->add_group(group_name, id);
                    Group new_group (group_name, current_person->get_name(), students_names, id);
                    Data::id_to_group[id] = new_group;
                    std::cout << "New group was made successfully!\n";
                    break;
                }
                case 4: {
                    current_person = nullptr;
                    std::string client_role = current_person->get_role() == type::student ? "student" : "tutor";
                    current_string = "main " + client_role;
                    std::cout << "You returned back\n";
                    return;
                }
                default:
                    std::cout << "wrong request\n";
                    break;
            }
        }
    }

    void Group_menu_for_student() {
        std::cout << current_group->get_info();
        int option;
        while (true) {
            std::cout << "You can:\n1) print_info\n2) choose_task\n3) back\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << current_group->get_info();
                    break;
                }
                case 2: {
                    std::cout << "Enter the task's name\n";
                    std::string name;
                    std::cin >> name;
                    current_string = "task student";
                    current_task = current_group->get_task(name);
                    return;
                }
                case 3: {
                    current_string = "profile student";
                    current_group = nullptr;
                    current_task = nullptr;
                    return;
                }
                default:
                    std::cout << "wrong request\n";
                    break;
            }
        }
    }

    void Task_menu_for_student() {
        std::cout << current_task->get_info();
        int option;
        while (true) {
            std::cout << "You can:\n1) print_info\n2) get_chat\n3) back\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << current_group->get_info();
                    break;
                }
                case 2: {
                    current_string = "chat student";
                    current_chat = current_task->get_discussion();
                    return;
                }
                case 3: {
                    current_string = "group student";
                    current_task = nullptr;
                    current_chat = nullptr;
                    return;
                }
                default:
                    std::cout << "wrong request\n";
                    break;
            }
        }
    }

    void Group_menu_for_tutor() {
        std::cout << current_group->get_info();
        int option;
        while (true) {
            std::cout << "You can:\n1) print_info\n2) print_students\n3) choose_task\n4) create_task\n5) add student\n6) back\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << current_group->get_info();
                    break;
                }
                case 2: {
                    for (auto s: current_group->get_students()) {
                        std::cout << s << '\n';
                    }
                    break;
                }
                case 3: {
                    std::string name;
                    std::cin >> name;
                    current_task = current_group->get_task(name);
                    current_string = "task tutor";
                    return;
                }
                case 4: {
                    std::cout << "Task's name:\n";
                    std::string name_of_task;
                    std::cin >> name_of_task;
                    std::string text_of_task;
                    std::cout << "Task's problem:\n";
                    std::cout << "Print stop_task at the end of the task from new line\n";
                    std::string current_cin;
                    std::cin >> current_cin;
                    while (current_cin != "stop_task") {
                        text_of_task += current_cin;
                        std::cin >> current_cin;
                    }
                    std::cout << "Task for:\n";
                    std::string student_name;
                    std::cin >> student_name;
                    current_group->add_task(name_of_task, text_of_task, student_name);
                    break;
                }
                case 5: {
                    std::cout << "Enter student's name\n";
                    std::string student_name;
                    std::cin >> student_name;
                    if (Data::name_to_person.find(student_name) == Data::name_to_person.end()) {
                        std::cout << "There is no such a student!\n";
                    }
                    else {
                        current_group->add_student(student_name);
                        Data::name_to_person[student_name].add_group(current_group->get_name(), current_group->get_id());
                        std::cout << "The student was added successfully\n";
                    }
                    break;
                }
                case 6: {
                    current_string = "group tutor";
                    current_group = nullptr;
                    current_task = nullptr;
                    current_chat = nullptr;
                    return;
                }
                default:
                    std::cout << "wrong request";
                    break;
            }
        }
    }

    void Task_menu_for_tutor() {
        std::cout << current_task->get_info();
        int option;
        while (true) {
            std::cout << "You can:\n1) print_info\n2) get_chat\n3) close_task\n4) back\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << current_group->get_info();
                    break;
                }
                case 2: {
                    current_string = "chat tutor";
                    current_chat = current_task->get_discussion();
                    return;
                }
                case 3: {
                    current_task->close();
                    break;
                }
                case 4: {
                    current_string = "group tutor";
                    current_task = nullptr;
                    current_chat = nullptr;
                    return;
                }
                    //return std::tuple<std::string, Person *, Group *, Task *, Chat *>("group", p, g, nullptr, nullptr);
                default:
                    std::cout << "wrong request\n";
                    break;
            }
        }
    }

    void Chat_menu() {
        std::cout << current_chat->get_name();
        int option;
        while (true) {
            std::cout << "You can:\n1) print_chat\n2) print last n messages\n3) write a message\n4) back\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << current_chat->get_all_chat();
                    break;
                }
                case 2: {
                    std::cout << "Enter how much messages you want to print?\n";
                    int number_of_messages;
                    std::cin >> number_of_messages;
                    std::cout << current_chat->get_last_n_messages(number_of_messages);
                    break;
                }
                case 3: {
                    std::cout << "Print message below\n";
                    std::string message;
                    std::cin >> message;
                    current_chat->Add_Message(message, current_person->get_name());
                    break;
                }
                case 4: {
                    current_chat = nullptr;
                    std::string client_role = current_person->get_role() == type::student ? "student" : "tutor";
                    current_string = "task " + client_role;
                    return;
                }
                default:
                    std::cout << "Bad guy! Wrong number!\n";
            }
        }
    }

public:
    Menu() {
        current_string = "main student";
    }
    ~Menu() = default;
    Menu(const Menu& to_copy) = default;
    Menu& operator = (const Menu& to_copy) = default;

    void basic_menu() {
        while (true)
        {
            if (current_string == "profile student" or current_string == "profile tutor")
            {
                Profile_menu();
            }
            else {
                if (current_string == "main student" or "main tutor")
                {
                    Main_menu();
                }
                else {
                    if (current_string == "group student")
                    {
                        Group_menu_for_student();
                    }
                    else {
                        if (current_string == "group tutor")
                        {
                            Group_menu_for_tutor();
                        }
                        
                        else {
                            if (current_string == "task student")
                            {
                                Task_menu_for_student();
                            }
                            else {
                                if (current_string == "task tutor")
                                {
                                    Task_menu_for_tutor();
                                }
                                else {
                                    if (current_string == "chat tutor" or current_string == "chat student")
                                    {
                                        Chat_menu();
                                    }
                                    else {
                                        std::cout << "Something went wrong in base menu";
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};

