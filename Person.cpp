#include "libs.h"

class Person {
private:
    std::string name;
    std::string password;
    std::set<std::pair<long long, std::string>> id_and_name_of_groups;
public:
    std::vector<long long> get_names_of_groups() {
        std::vector <std::string> names_of_groups;
        for (auto p: id_and_name_of_groups) {
            names_of_groups.push_back(p.second);
        }
        return names_of_groups;
    }
};
