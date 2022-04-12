#pragma once
#include <vector>
#include <set>
#include <string>
#include <map>

using std::vector;
using std::set;
using std::map;
using std::string;
using std::pair;

class Chat {
private:
    struct Message {
        string messaging_person;
        string text;
        Message() = default;
        Message(const string& text_constr, const string& person) {
            messaging_person = person;
            text = text_constr;
        }
        Message(const Message& copy) = default;
        ~Message() = default;
    };
    vector<Message> messages;
    string all_chat;
//    std::fstream chat_file;
public:
    string chat_name;
    set<string> people_in_chat;
    explicit Chat(const string& chat_name_const, const set<string>& people_in_chat_constr) {
        chat_name = chat_name_const;
        messages = vector<Message>();
        people_in_chat = people_in_chat_constr;
        all_chat = "";
    }
    void Add_Message(const string& message, const string& messaging_person) {
        Message message_to_add = Message(message, messaging_person);
        messages.push_back(message_to_add);
        all_chat += messaging_person + ": " + message + "\n\n";
    };
    Message& Get_Message(int number) {
        return messages[number];
    }
    [[nodiscard]] const Message& Get_Message(int number) const {
        return messages[number];
    }
    string get_all_chat() {
        return all_chat;
    }
    string get_last_n_messages(int number) {
        string ans;
        if (number > messages.size()) {
            return all_chat;
        }
        for (int i = static_cast<int>(messages.size()) - number; i < messages.size(); ++i) {
            ans += messages[i].messaging_person + ": " + messages[i].text + "\n\n";
        }
        return ans;
    }
};

#ifndef ATP_PROJECT_CHAT_H
#define ATP_PROJECT_CHAT_H

#endif //ATP_PROJECT_CHAT_H