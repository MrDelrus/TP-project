#pragma once
#include "library.h"
#include "Person.cpp"
#include "Group.cpp"

class Data {
public:
    static std::map<std::string, Person> name_to_person;
    static std::map<long long, Group> id_to_group;
};

std::map<long long, Group> Data::id_to_group = std::map<long long, Group>();
std::map<std::string, Person> Data::name_to_person = std::map<std::string, Person>();