#pragma once
#include <string>
#include <set>
#include <iostream>
#include <utility>

class Person {
private:
    std::string name;
    std::set<int> groups_id;
public:
    std::set<int> GetGroupsIds() {
        return groups_id;
    }

//    int ChooseGroup(const std::string& group_name, std::map<std::string, Group*>& groups) const {
//        return groups[group_name]->GetId();
//    }

    [[nodiscard]] std::string GetName() const {
        return name;
    }

    bool operator < (const Person& person) const {
        return (name < person.name);
    }
};
 
class Tutor : public Person {
private:
    std::string name;
public:
    explicit Tutor(std::string  name): name(std::move(name)) {}
    Tutor(const Tutor&) = default;
    ~Tutor() = default;
};
 
class Student : public Person {
private:
    std::string name;
public:
    explicit Student(std::string  name): name(std::move(name)) {}
    Student(const Student&) = default;
    ~Student() = default;
};
 
#ifndef ATP_PROJECT_STUDENTTUTORGROUP_H
#define ATP_PROJECT_STUDENTTUTORGROUP_H
 
#endif //ATP_PROJECT_STUDENTTUTORGROUP_H
