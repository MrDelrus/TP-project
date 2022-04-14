#include "library.h"
#include "Person.cpp"
#include "Group.cpp"

class Data {
public:
    static std::map<std::string, Person> name_to_person;
    static std::map<long long, Group> id_to_group;
};