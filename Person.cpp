#pragma once
#include <utility>
#include <iostream>
#include "library.h"

class Person {
private:
    std::string name;
    std::string password;
    type role;
public:
    std::map<std::string, long long> name_to_id_of_groups;
    Person() {
        name = "";
        password = "";
        role = type::student;
    }
    Person(std::string name, std::string  password, const type& role) : name(std::move(name)), password(std::move(password)), role(role) {
        name_to_id_of_groups = std::map<std::string, long long>(); 
    }
    Person(const Person& copy) = default;
    Person& operator = (const Person& copy) = default;
    ~Person() = default;

    [[nodiscard]] const std::string& get_name() const {
        return name;
    }

    [[nodiscard]] const std::string& get_password() const {
        return password;
    }

    bool check_password(const std::string& try_password) {
        return try_password == password;
    }

    [[nodiscard]] const type& get_role() const {
        return role;
    }

    std::string get_groups() {
        std::string answer;
        for (const auto& p: name_to_id_of_groups) {
            answer += p.first + "\n";
        }
        return answer;
    }

    void add_group(const std::string& name_of_group, long long id_of_group) {
        if (name_to_id_of_groups.size() >= 8) {
            std::cout << "Your number of groups should not be more than 8!\n";
            return;
        }
        name_to_id_of_groups[name_of_group] = id_of_group;
    }

    friend class PersonParser;
};