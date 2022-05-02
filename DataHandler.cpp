#pragma once
#include "JsonParser.cpp"


class DataHandler {
public:
    static std::string save_everything(const std::string& file_name) {
        json storage;
        json name_to_person_json;
        for (auto& pair : (Data::name_to_person)) {
            name_to_person_json[pair.first] = PersonParser::get_json_from_person(pair.second);
        }
        json name_to_group_json;
        for (auto& pair: (Data::name_to_group)) {
            name_to_group_json[pair.first] = GroupParser::get_json_from_group(pair.second);
        }
        storage.push_back(name_to_person_json);
        storage.push_back(name_to_group_json);
        std::ofstream file;
        file.open(file_name);
        file << storage.dump(4);
        file.close();
        return file_name;
    }
    static void load_everything(const std::string& file_name) {
        std::ifstream file(file_name);
        std::string storage_string = "";
        std::string temp;
        if (file.is_open()) {
            while (getline(file, temp)) {
                storage_string += temp;
            }
            file.close();
        }
        else {
            throw std::runtime_error("Unable to open file " + file_name);
        }
        if (storage_string == "") {
            return;
        }
        json storage = json::parse(storage_string);
        // std::cout << storage << "\n";
        Data::name_to_person = std::map<std::string, Person>();
        Data::name_to_group = std::map<std::string, Group>();
        for (json::iterator it = storage[0].begin(); it != storage[0].end(); ++it) {
            Data::name_to_person[it.key()] = PersonParser::get_person_from_json(it.value());
            //answer.tasks[it.key()] = TaskParser::get_task_from_json(it.value());
        }
        for (json::iterator it = storage[1].begin(); it != storage[1].end(); ++it) {
            Data::name_to_group[it.key()] = GroupParser::get_group_from_json(it.value());
        }
    }
};
