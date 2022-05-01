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
    static std::map<long long, Group> id_to_group;
};

std::map<long long, Group> Data::id_to_group = std::map<long long, Group>();
std::map<std::string, Person> Data::name_to_person = std::map<std::string, Person>();