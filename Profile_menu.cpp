#include "libs.h"

class Profile_menu {
private:
    std::string name;
    Person* person;
    std::map<std::string, long long> groups; // name -> id
    void print_groups() {
        std::string text = "Groups:\n";
        for (auto g : groups) {
            text += Data::data_group[g.second].name + '\n';
        }
        std::cout << text;
    };

    Main_menu return_to_menu() {
        return Main_menu();
    }
public:
    Profile_menu(Person) {

    }

};