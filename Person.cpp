#include "libs.h"

Person::Person() {
    name = "";
    password = "ghdjkdsghkfjdh";
    role = student;
    name_to_id_of_groups = map<string, long long>();
}

Person::Person(string name_c, string pass_c, type type_c, map<string, long long> to_copy) {
    name = std::move(name_c);
    password = std::move(pass_c);
    role = type_c;
    name_to_id_of_groups = std::move(to_copy);
}

std::vector<std::string> Person::get_names_of_groups() {
    std::vector <std::string> names_of_groups;
    for (const auto& p: name_to_id_of_groups) {
        names_of_groups.push_back(p.first);
    }
    return names_of_groups;
}