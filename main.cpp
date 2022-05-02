#include <iostream>
#include <fstream>
#include <map>
#include "DataHandler.cpp"

using json = nlohmann::json;

void json_check() {
    std::string s = R"({"pi":3.141})";
    json j = json::parse(s);
    std::cout << j["pi"] << "\n";
    std::cout << j << "\n";
    json j_big;
    j_big["e"] = j;
    std::cout << j_big << "\n";
    std::cout << j_big["e"]["pi"] << "\n";
    std::cout << j_big["e"] << "\n";
    json j3;
    j3["list"] = {0, 1, 2};
    std::cout << j3 << "\n";
    std::cout << j3["list"][0] << "\n";
    json j4 = json::parse(R"({"list":[0,1,2]})");
    std::cout << j4["list"][1] << "\n";
    for (auto& i : j4["list"]) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << j4 << "\n";
    for (auto& i : j4) {
        std::cout << i << "\n";
    }
    for (json::iterator it = j4.begin(); it != j4.end(); ++it) {
        std::cout << it.key() << " : " << it.value() << "\n";
    }
}

void message_check() {
    MessageArrayParser mdh = MessageArrayParser();
    Message m1 = Message("Petya", "Hello from Petya!");
    Message m2 = Message("Vasya", "Hello from Vasya!");
    mdh.add_message_to_json(m1);
    mdh.add_message_to_json(m2);
    std::cout << mdh.get_json() << "\n";
    std::vector<Message> get = mdh.get_messages();
    for (auto& msg : get) {
        std::cout << msg.text << "\n";
    }
}

void chat_check() {
    std::set<std::string> people_in_chat;
    people_in_chat.insert("Petya");
    people_in_chat.insert("Vasya");
    Chat chat1 = Chat("Petya and Vasya", people_in_chat);
    chat1.Add_Message("Hello", "Vasya");
    chat1.Add_Message("Hello from Petya!", "Petya");
    json chat_json1 = ChatParser::get_json_from_chat(chat1);
    std::cout << chat_json1 << "\n";
}

void person_check() {
    Person Petya = Person("Petya", "1234", type::student);
    Person Vasya = Person("Vasya", "7622", type::student);
    Vasya.add_group("2a");
    json Vasya_json = PersonParser::get_json_from_person(Vasya);
    std::cout << Vasya_json << "\n";
    Person Vasya_clone = PersonParser::get_person_from_json(Vasya_json);
    std::cout << Vasya_clone.get_name() << " " << Vasya_clone.get_password() << " " << Vasya_clone.get_groups() <<
    " " << "\n";
}

void task_check() {
    std::string problem = "Given a and b. Find a + b";
    std::set<std::string> people_in_chat;
    people_in_chat.insert("Petya");
    people_in_chat.insert("Vasya");
    Chat chat1 = Chat("Petya and Vasya", people_in_chat);
    chat1.Add_Message("Hello", "Vasya");
    chat1.Add_Message("Hello from Petya!", "Petya");
    Task task1 = Task("Task TP 25", problem, "Bogdanov", "Zolin");
    task1.change_problem("Given a and b. Find a + b + a * b");
    Chat* discussion = task1.get_discussion();
    (*discussion) = chat1;
    json task1_json = TaskParser::get_json_from_task(task1);
    std::cout << task1_json << "\n";
}

void group_check() {
    std::string problem = "Given a and b. Find a + b";
    std::set<std::string> people_in_chat;
    people_in_chat.insert("Petya");
    people_in_chat.insert("Vasya");
    Chat chat1 = Chat("Petya and Vasya", people_in_chat);
    chat1.Add_Message("Hello", "Vasya");
    chat1.Add_Message("Hello from Petya!", "Petya");
    Task task1 = Task("Task TP 25", problem, "Bogdanov", "Zolin");
    task1.change_problem("Given a and b. Find a + b + a * b");
    Chat* discussion = task1.get_discussion();
    (*discussion) = chat1;
    Group main_group = Group("2a", "Bogdanov", people_in_chat);
    main_group.add_task(task1);
    json group_json = GroupParser::get_json_from_group(main_group);
    Group main_group_clone = GroupParser::get_group_from_json(group_json);
    std::cout << main_group_clone.get_info() << "\n";
    std::cout << "Json view:\n" << group_json << "\n";
}

int main() {
    DataHandler::load_everything("/home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/storage.txt");
//    Person Petya1 = Person("Petya1", "1234", type::student);
//    Person Vasya1 = Person("Vasya1", "7622", type::student);
//    Data::name_to_person["Petya1"] = Petya1;
//    Data::name_to_person["Vasya1"] = Vasya1;
//    Vasya1.add_group("2a", 5674);
    Menu main_menu = Menu();
    main_menu.basic_menu();
    DataHandler::save_everything("/home/ilya/MIPT/C++/CLionProjects/TP-project/newtp/TP-project/storage.txt");
    return 0;
}

//www.plantuml.com/plantuml/png/fLL1Rziy3BtxL_3e-FjSRDUsCmfqm4u31hHtGx4KHwWi6HBTRSZotrVHyXpBgMribo8q7yd7HufzSCWiTerAAi
// MSWyyC6PmI083_u7IGGl4pEEItjmrhx-c7Gojr_Jzy4zOPNO1cZIZHb2tPxuKgesjGnWT-iQPh2v3SHzNUICv9GfNpt8IyeqtmfESNd85XFfOPYH6Vk
// VjkSBVCkU_6yWY2Fri1rYYngVS_tOpjIrwQGz-E6t8q0eycebSBB7rCkejHUsCKL4THlPG3oVGYCiOJPKhdQQUxkvMgWTkyBkEyzwNNUzmbvq5-cWMS
// O2hU20N9jqycTcE7nf8scsPmOHJWiED2ewDmjod-cRcN0l3jRpoliH_IJV9qjwQjr0SpHxqQoKbUNsMgxYOZJaYSCoeOPxnUkrB6YNKi-Lv5XSPUQbH
// GfK7QTH5eW0igX4nJAkUaNweipwczi6hqEthduOb8LvfMwBzVjDQQlH9DX7ZsxBD-2oFNKqyy6zOiSZyU6GANhkgSaqR_mwvKHwPhKGQ2IpEZelqgZ9
// NJrItmUfEoNcwV8Wbwax7zhgx_OyWAQ8LfrJnctBL6ECTgKG1doDvTcu1A9oEa6lJQ9oy6KFp0cGeX0wcbcCCXfKkbHj3m2Jv-yCgG1bwPhxr_q2QOz
// _TFQBiAYuA4ckiKKuj04Kr_LXz3VjqjQK-dlcpUK14cI1rgHavwLndGQOzST4VezbrPvSol8LuTnvuvMH6Hi6fv16YOr4l-rfg3L689GdpBWx7zFTa6
// 3Gzp0YOCDJdF5WCMSv0UuRCV6ethvkPN4VGVF_IQZpO9FPhzYtiGcdUD-Wq0

//int main() {
//    Menu main_menu = Menu();
//    main_menu.basic_menu();
//}

