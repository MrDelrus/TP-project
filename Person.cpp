#include "libs.h"

class Person {
private:
    std::string name;
    std::string password;
    type role;
    std::map<std::string, long long> name_to_id_of_groups;
public:
    Person(type )
    std::vector<long long> get_names_of_groups() {
        std::vector <std::string> names_of_groups;
        for (auto p: id_and_name_of_groups) {
            names_of_groups.push_back(p.second);
        }
        return names_of_groups;
    }

    friend Profile_menu;
    friend Student_menu;
    friend Tutor_menu;
};