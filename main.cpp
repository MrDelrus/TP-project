#pragma once
#include <string>
#include <set>
#include <iostream>

//class Person {
//private:
//    std::string name;
//public:
//
//    std::string GetName() {
//        return name;
//    }
//
//    bool operator < (const Person& person) const {
//        return (name < person.name);
//    }
//};
//
//class Tutor : public Person {
//private:
//    std::string name;
//public:
//    explicit Tutor(std::string  name): name(std::move(name)) {}
//    Tutor(const Tutor&) = default;
//    ~Tutor() = default;
//};

struct X
{
    enum direction { left = 'l', right = 'r' };
};

int main() {
    X x;
    X* p = &x;

    int a = X::direction::left; // allowed only in C++11 and later
    int b = X::left;
    int c = x.left;
    int d = p->left;
hii
    return 0;
}
