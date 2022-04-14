#include <utility>

#include "library.h"

class Person {
private:
    std::string name;
    std::string password;
    type role;
public:
    std::map<std::string, long long> name_to_id;

    Person(std::string  name, std::string  password, const type& role) : name(std::move(name)), password(std::move(password)), role(role) {}
    Person(const Person& copy) = default;
    Person& operator= (const Person& copy) = default;
    ~Person() = default;

    const std::string& get_name() {
        return name;
    }
    bool check_password(const std::string& try_password) {
        return try_password == password;
    }
    const type& get_role() {
        return role;
    }

};