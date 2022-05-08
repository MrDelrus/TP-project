#pragma once
#include <utility>
#include <iostream>
#include "library.h"

class Person {
private:
    std::string name;
    std::string password;
    type role;
    std::set<std::string> groups_names;
public:
    //std::map<std::string, long long> name_to_id_of_groups;
    Person() {
        name = "";
        password = "";
        role = type::student;
    }
    Person(std::string name_c, std::string  password, const type& role) : name(std::move(name_c)), password(std::move(password)), role(role) {
        //name_to_id_of_groups = std::map<std::string, long long>();
        groups_names = std::set<std::string>();
    }
    Person(const Person& copy) = default;
    Person& operator = (const Person& copy) = default;
    ~Person() = default;
    std::set<std::string>& set_groups_names() {
        return groups_names;
    }
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
        for (const auto& p: groups_names) {
            answer += p + "\n";
        }
        return answer;
    }

    void add_group(const std::string& name_of_group) {
        if (groups_names.size() >= 8) {
            std::cout << "Your number of groups should not be more than 8!\n";
            return;
        }
        if (groups_names.find(name_of_group) != groups_names.end()) {
            std::cout << "this group exists!\n";
            return;
        }
        groups_names.insert(name_of_group);
    }

    friend class PersonParser;
};