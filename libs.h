#pragma once
#include <utility>
#include <vector>
#include <set>
#include <string>
#include <map>
#include "Task.cpp"
//#include "Main_menu.cpp"
//#include "Task.cpp"
//#include "Chat.cpp"
//#include "Person.cpp"
//#include "Profile_menu.cpp"
//#include "Student_menu.cpp"
//#include "Tutor_menu.cpp"

using std::vector;
using std::set;
using std::map;
using std::string;
using std::pair;

enum type { student, tutor };


class Person {
private:
    std::string name;
    std::string password;
    type role;
    std::map<std::string, long long> name_to_id_of_groups;
public:
    Person();
    Person(const Person& to_copy);
    Person(string name_c, string pass_c, type type_c, map<string, long long> to_copy);
    std::vector<std::string> get_names_of_groups();
    type get_role();
    string get_name();
    bool check_password(const std::string& to_check);
    const map<string, long long>& get_map_name_id();
//    friend Profile_menu;
//    friend Student_menu;
//    friend Tutor_menu;
};


class Group {
private:
    long long id;
    std::string name;
    std::string tutor_name;
    std::vector <std::string> students_names;
    std::map <std::string, Task> tasks;
public:
    string get_name() { return name; }
    Group() = default;
    Group(long long id, std::string name, std::string tutor_name,
          std::vector <std::string> students_names) :
            id(id), name(std::move(name)), tutor_name(std::move(tutor_name)), students_names(std::move(students_names)) {}
    ~Group() = default;

    std::string get_info();
};

class Data {
private:
    static std::map<std::string, Person> data_people; // name - Person
    static std::map<long long, Group> data_group; // id - Group
public:
    static const map<string, Person>& get_name_person() {
        return data_people;
    }
    static const map<long long, Group>& get_id_group() {
        return data_group;
    }
};


