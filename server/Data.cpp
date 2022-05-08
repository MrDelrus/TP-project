#pragma once
#include "library.h"
#include "Person.cpp"
#include "Group.cpp"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

class Data {
public:
    static std::map<std::string, Person> name_to_person;
    static std::map<std::string, Group> name_to_group;
    static void add_student_into_group(const std::string& student_name, const std::string& group_name) {
        name_to_person[student_name].add_group(group_name);
        name_to_group[group_name].add_student(student_name);
    }
};

std::map<std::string, Group> Data::name_to_group = std::map<std::string, Group>();
std::map<std::string, Person> Data::name_to_person = std::map<std::string, Person>();