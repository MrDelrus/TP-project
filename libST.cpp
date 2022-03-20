#include <string>
#include "ProblemTask.h"
#include "Chat.h"
 
class Person {
private:
    std::string name;
    std::set<Group*> groups;
public:
 
    std::set<Group*> GetGroups() {
        return groups;
    }
 
    Group* ChooseGroup(std::string group_name) {
        for (auto g: groups) {
            if (group_name == g->GetName()) {
                return g;
            }
        }
    }
 
    std::string GetName() {
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
    Tutor(const std::string& name): name(name) {}
    Tutor(const Tutor&) = default;
    ~Tutor() = default;
};
 
class Student : public Person {
private:
    std::string name;
public:
    Student(const std::string& name): name(name) {}
    Student(const Student&) = default;
    ~Student() = default;
};
 
#ifndef ATP_PROJECT_STUDENTTUTORGROUP_H
#define ATP_PROJECT_STUDENTTUTORGROUP_H
 
#endif //ATP_PROJECT_STUDENTTUTORGROUP_H
