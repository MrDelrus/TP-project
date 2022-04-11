#include "libs.h"

Person::Person() {
    name = "";
    password = "ghdjkdsghkfjdh";
    role = student;
    name_to_id_of_groups = map<string, long long>();
}

Person::Person(const Person& to_copy) {
    name = to_copy.name;
    password = to_copy.password;
    role = to_copy.role;
    name_to_id_of_groups == to_copy.name_to_id_of_groups;
}

Person::Person(string name_c, string pass_c, type type_c, map<string, long long> to_copy) {
    name = std::move(name_c);
    password = std::move(pass_c);
    role = type_c;
    name_to_id_of_groups = std::move(to_copy);
}

string Person::get_name() {
    return name;
}

const map<string, long long>& Person::get_map_name_id() {
    return name_to_id_of_groups;
}

std::vector<std::string> Person::get_names_of_groups() {
    std::vector <std::string> names_of_groups;
    for (const auto& p: name_to_id_of_groups) {
        names_of_groups.push_back(p.first);
    }
    return names_of_groups;
}