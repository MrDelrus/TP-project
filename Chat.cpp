#pragma once
#include <string>
#include <vector>
#include "libs.h"
#include <set>
 
class Chat {
private:
    struct Message { //add time?
        Person messaging_person;
        std::string text;
        Message(const std::string& text_constr, const Person& person) {
            messaging_person = person;
            text = text_constr;
        }
        Message(const Message& copy) = default;
        ~Message() = default;
    };
    std::vector<Message> messages;
//    std::fstream chat_file;
public:
    std::string chat_name;
    std::set<Person*> people_in_chat;
    Chat(const std::string& chat_name_const, const std::set<Person*>& people_in_chat_constr) {
        chat_name = chat_name_const;
        messages = std::vector<Message>();
        people_in_chat = people_in_chat_constr;
    }
    void Add_Message(const std::string& message, const Person& messaging_person) {
        Message message_to_add = Message(message, messaging_person);
        messages.push_back(message_to_add);
    };
    Message& Get_Message(int number) {
        return messages[number];
    }
    const Message& Get_Message(int number) const {
        return messages[number];
    }
    std::string Get_Last_n_Messages(int number) const {
        std::string ans = "";
        if (number > messages.size()) {
            for (const auto & message : messages) {
                ans += message.messaging_person.GetName() + ": " + message.text + "\n\n";
            }
            return ans;
        }
        if (number < 0) {
            return ans;
        }
        for (int i = messages.size() - number; i < messages.size(); ++i) {
            ans += messages[i].messaging_person.GetName() + ": " + messages[i].text + "\n\n";
        }
        return ans;
    }
    std::string Get_All_Chat() {
        std::string ans = "";
        for (auto & message : messages) {
            ans += message.messaging_person.GetName() + ": " + message.text + "\n\n";
        }
        return ans;
    }
};
 
#ifndef ATP_PROJECT_CHAT_H
#define ATP_PROJECT_CHAT_H
 
#endif //ATP_PROJECT_CHAT_H
