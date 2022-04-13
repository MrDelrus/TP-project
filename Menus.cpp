#pragma once
#include "libs.h"
#include <iostream>

class Menu {
private:
    std::string current_string;
    Person* current_person;
    Group* current_group;
    Task* current_task;
    Chat* current_chat;
public:
    void Group_menu_for_student(Person *p, Group *g) {
        std::cout << g->get_info();
        std::cout << "You can:\n1) print_info\n2) print_tasks\n3) choose_task\n4) back\n";
        int option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << g->get_info();
                    break;
                }
                case 2: {
                    std::cout << g->get_tasks();
                    break;
                }
                case 3: {
                    std::string name;
                    std::cin >> name;
                    current_string = "task";
                    current_person = p;
                    current_group = g;
                    current_task = &(g->get_task(name));
                    break;
                }
//                    return std::tuple<std::string, Person *, Group *, Task *>("task", p, g, &(g->tasks[name]));
                case 4: {
                    current_string = "person";
                    current_person = p;
                    current_group = nullptr;
                    current_task = nullptr;
                    break;
                }
//                    return std::tuple<std::string, Person *, Group *, Task *>("person", p, nullptr, nullptr);
                default:
                    std::cout << "wrong request\n";
            }
        }
    }

    void Task_menu_for_student(Person *p, Group *g, Task *t) {
        std::cout << t->get_info();
        std::cout << "You can:\n1) print_info\n2) get_chat\n3) back\n";
        std::string option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case "print_info": {
                    std::cout << g->get_info();
                    break;
                }
                case "get_chat": {
                    current_string = "chat";
                    current_person = p;
                    current_group = g;
                    current_task = t;
                    current_chat = &(t->get_discussion);
                }
//                    return std::tuple<std::string, Person *, Group *, Task *, Chat *>("chat", p, g, t, &(t->get_discussion));
                case "back": {
                    current_string = "group";
                    current_person = p;
                    current_group = g;
                    current_task = nullptr;
                    current_chat = nullptr;
                }
//                    return std::tuple<std::string, Person *, Group *, Task *, Chat *>("group", p, g, nullptr, nullptr);
                default:
                    std::cout << "wrong request\n";
            }
        }
    }

    void Group_menu_for_student(Person *p, Group *g) {
        std::cout << g->get_info();
        std::cout
                << "You can:\n1) print_info\n2) print_tasks\n3) print_students\n4) choose_task\n5) create_task\n6) back\n";
        int option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case 1:
                    std::cout << g->get_info();
                    break;
                case 2:
                    std::cout << g->get_tasks();
                    break;
                case 3:
                    std::cout << g->get_students();
                    break;
                case 4:
                    std::string name;
                    std::cin >> name;
                    return std::tuple<std::string, Person *, Group *, Task *>("task", p, g, &(g->tasks[name]));
                case 5:
                    std::string task_name, problem, student_name;
                    std::cout << "Task's name:\n";
                    std::cin >> task_name;
                    std::cout << "Task's problem:\n";
                    std::cin >> problem;
                    std::cout << "Task for:\n";
                    std::cin >> student_name;
                    g->add_task(task_name, problem, p->name, student_name);
                    break;
                case 6:
                    return std::tuple<std::string, Person *, Group *, Task *>("person", p, nullptr, nullptr);
                default:
                    std::cout << "wrong request\n";
            }
        }
    }

    std::tuple<std::string, Person *, Group *, Task *, Chat *> Task_menu_for_student(Person *p, Group *g, Task *t) {
        std::cout << t->get_info();
        std::cout << "You can:\n1) print_info\n2) get_chat\n3) close_task\n4) back\n";
        int option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case 1:
                    std::cout << g->get_info();
                    break;
                case 2:
                    return std::tuple<std::string, Person *, Group *, Task *, Chat *>("chat", p, g, t, &(t->discussion));
                case 3:
                    t->close_task();
                    return std::tuple<std::string, Person *, Group *, Task *, Chat *>("group", p, g, nullptr, nullptr);
                    break;
                case 4:
                    return std::tuple<std::string, Person *, Group *, Task *, Chat *>("group", p, g, nullptr, nullptr);
                default:
                    std::cout << "wrong request\n";
            }
        }
    }
};
