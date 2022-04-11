#include "libs.h"
#include "Student_menu.cpp"
#include "Tutor_menu.cpp"

//
//class Main_menu {
//public:
//    Main_menu() = default;
//    Profile_menu& sign_up(const std::string& name, const std::string& password, enum type) {
//        return Profile_menu();
//    }
//    Profile_menu& sign_in(const std::string& name, const std::string& password) {
//        auto it = Data::data_people.find(name);
//        if (it == Data::data_people.end()) {
//            throw std::runtime_error("Wrong name or password");
//        } else {
//            return Profile_menu(it.second);
//        }
//    }
//};