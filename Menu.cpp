// glhf there too

#include "library.h"
#include <iostream>
#include "Person.cpp"
#include "Group.cpp"

class Menu {
private:
    std::string current_string;
    Person* current_person = nullptr;
    Group* current_group = nullptr;
    Task* current_task = nullptr;
    Chat* current_chat = nullptr;
public:
    Menu();
    ~Menu();

    void Group_menu_for_student(Person *p, Group *g) {
        std::cout << g->get_info();
        std::cout << "You can:\n1) print_info\n2) choose_task\n3) back\n";
        int option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << g->get_info();
                    break;
                }
                case 2: {
                    std::string name;
                    std::cin >> name;
                    current_string = "task";
                    current_person = p;
                    current_group = g;
                    current_task = g->get_task(name);
                    return;
                }
                case 3: {
                    current_string = "person";
                    current_person = p;
                    current_group = nullptr;
                    current_task = nullptr;
                    return;
                }
                default:
                    std::cout << "wrong request\n";
            }
        }
    }

    void Task_menu_for_student(Person *p, Group *g, Task *t) {
        std::cout << t->get_info();
        std::cout << "You can:\n1) print_info\n2) get_chat\n3) back\n";
        int option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cout << g->get_info();
                    break;
                }
                case 2: {
                    current_string = "chat";
                    current_person = p;
                    current_group = g;
                    current_task = t;
                    current_chat = t->get_discussion();
                    return;
                }
                case 3: {
                    current_string = "group";
                    current_person = p;
                    current_group = g;
                    current_task = nullptr;
                    current_chat = nullptr;
                    return;
                }
                default:
                    std::cout << "wrong request\n";
            }
        }
    }

    // аналогично дальше

    void Group_menu_for_student(Person *p, Group *g) {
        std::cout << g->get_info();
        std::cout
                << "You can:\n1) print_info\n2) print_students\n3) choose_task\n4) create_task\n5) back\n";
        int option;
        while (true) {
            std::cin >> option;
            switch (option) {
                case 1:
                    std::cout << g->get_info();
                    break;
                case 2:
                    for (auto s: g->get_students()) {
                        std::cout << s << '\n';
                    }
                    break;
                case 3:
                    std::string name;
                    std::cin >> name;
                    // добить
                    /*
                    return;
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
    } */
            }
        }
    }
};
