#pragma once
#include <vector>
#include <set>
#include <string>
#include <map>
#include "Main_menu.cpp"
#include "Task.cpp"
#include "Person.cpp"
#include "Profile_menu.cpp"
#include "Student_menu.cpp"
#include "Tutor_menu.cpp"

using std::vector;
using std::set;
using std::map;
using std::string;
using std::pair;

enum type { student, tutor};


class Person {
private:
    std::string name;
    std::string password;
    type role;
    std::map<std::string, long long> name_to_id_of_groups;
public:
    Person();
    Person(string name_c, string pass_c, type type_c, map<string, long long> to_copy);
    std::vector<std::string> get_names_of_groups();

    friend Profile_menu;
    friend Student_menu;
    friend Tutor_menu;
};


class Group {
private:
    long long id;
    std::string name;
    std::string tutor_name;
    std::vector <std::string> students_names;
    std::map <std::string, Task> tasks;
public:

    Group(long long id, const std::string &name, const std::string &tutor_name,
          std::vector <std::string> students_names) :
            id(id), name(name), tutor_name(tutor_name), students_names(students_names) {}
    ~Group() = default;

    std::string info();

};

class Data {
private:
    static std::map<std::string, Person> data_people; // name - Person
    static std::map<long long, Group> data_group; // id - Group
public:
    friend Main_menu;
};


