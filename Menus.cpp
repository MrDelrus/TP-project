#include "libs.h"
#include <iostream>

std::tuple<std::string, Person*, Group*, Task*> Group_menu_for_student(Person* p, Group* g) {
    std::cout << g->get_info();
    std::cout << "You can:\n1) print_info\n2) print_tasks\n3) choose_task\n4) back\n";
    std::string option;
    while (true) {
        std::cin >> option;
        switch (option) {
            case "print_info":
                std::cout << g->get_info();
                break;
            case "print_tasks":
                std::cout << g->get_tasks();
                break;
            case "choose_task":
                std::string name;
                std::cin >> name;
                return std::tuple<std::string, Person*, Group*, Task*>("task", p, g, &(g->tasks[name]));
            case "back":
                return std::tuple<std::string, Person*, Group*, Task*>("person", p, nullptr, nullptr);
            default:
                std::cout << "wrong request\n";
        }
    }
}

std::tuple<std::string, Person*, Group*, Task*, Chat*> Task_menu_for_student(Person* p, Group* g, Task* t) {
    std::cout << t->get_info();
    std::cout << "You can:\n1) print_info\n2) get_chat\n3) back\n";
    std::string option;
    while (true) {
        std::cin >> option;
        switch (option) {
            case "print_info":
                std::cout << g->get_info();
                break;
            case "get_chat":
                return std::tuple<std::string, Person*, Group*, Task*, Chat*>("chat", p, g, t, &t->discussion);
            case "back":
                return std::tuple<std::string, Person*, Group*, Task*, Chat*>("group", p, g, nullptr, nullptr);
            default:
                std::cout << "wrong request\n";
        }
    }
}

std::tuple<std::string, Person*, Group*, Task*> Group_menu_for_student(Person* p, Group* g) {
    std::cout << g->get_info();
    std::cout << "You can:\n1) print_info\n2) print_tasks\n3) print_students\n4) choose_task\n5) create_task\n6) back\n";
    std::string option;
    while (true) {
        std::cin >> option;
        switch (option) {
            case "print_info":
                std::cout << g->get_info();
                break;
            case "print_tasks":
                std::cout << g->get_tasks();
                break;
            case "print_students":
                std::cout << g->get_students();
                break;
            case "choose_task":
                std::string name;
                std::cin >> name;
                return std::tuple<std::string, Person*, Group*, Task*>("task", p, g, &(g->tasks[name]));
            case "create_task":
                std::string task_name, problem, student_name;
                std::cout << "Task's name:\n";
                std::cin >> task_name;
                std::cout << "Task's problem:\n";
                std::cin >> problem;
                std::cout << "Task for:\n";
                std::cin >> student_name;
                g->add_task(task_name, problem, p->name, student_name);
                break;
            case "back":
                return std::tuple<std::string, Person*, Group*, Task*>("person", p, nullptr, nullptr);
            default:
                std::cout << "wrong request\n";
        }
    }
}

std::tuple<std::string, Person*, Group*, Task*, Chat*> Task_menu_for_student(Person* p, Group* g, Task* t) {
    std::cout << t->get_info();
    std::cout << "You can:\n1) print_info\n2) get_chat\n3) close_task\n4) back\n";
    std::string option;
    while (true) {
        std::cin >> option;
        switch (option) {
            case "print_info":
                std::cout << g->get_info();
                break;
            case "get_chat":
                return std::tuple<std::string, Person*, Group*, Task*, Chat*>("chat", p, g, t, &t->discussion);
            case "close_task":
                t->close_task();
                return std::tuple<std::string, Person*, Group*, Task*, Chat*>("group", p, g, nullptr, nullptr);
                break;
            case "back":
                return std::tuple<std::string, Person*, Group*, Task*, Chat*>("group", p, g, nullptr, nullptr);
            default:
                std::cout << "wrong request\n";
        }
    }
}
