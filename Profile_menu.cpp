#include "libs.h"
#include <iostream>

class Profile_menu {
private:
    std::string name;
    Person person;
    std::map<std::string, long long> groups; // name -> id
    void print_groups() {
        std::string text = "Groups:\n";
        for (auto g : groups) {
            auto helper = Data::get_id_group();
            text += helper[g.second].get_name() + '\n';
        }
        std::cout << text;
    };
    /* Main_menu return_to_menu() {
        return Main_menu();
    } */
public:
    explicit Profile_menu(Person p): name(p.get_name()), person(p), groups(p.get_map_name_id()) {}
};