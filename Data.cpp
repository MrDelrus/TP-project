#include "libs.h"

class Data {
private:
    static std::map<std::string, Person> data_people; // name - Person
    static std::map<long long, Group> data_group; // id - Group
public:
    friend Main_menu;
};