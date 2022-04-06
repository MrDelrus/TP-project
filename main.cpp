#pragma once
#include <string>
#include <set>
#include <iostream>

class Person {
private:
    std::string name;
public:

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
    explicit Tutor(std::string  name): name(std::move(name)) {}
    Tutor(const Tutor&) = default;
    ~Tutor() = default;
};

int main() {
    Tutor tutor("gh");
    std::cout << tutor.GetName();
    return 0;
}
