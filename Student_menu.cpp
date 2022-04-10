#include "libs.h"

class Student_menu: Profile_menu {
private:
    std::string name;

public:
    Student_menu(Person) {

    };

    Group_menu_for_student choose_group_EXCEPTION(std::string name) {
        if (groups.find(name) == groups.end()) {
            throw std::runtime_error("Not found");
        }
    }

};