// glhf
#pragma once
#include "library.h"

struct Message {
    std::string messaging_person;
    std::string text;
    Message() = default;
    Message(const std::string& text_constr, const std::string& person) {
        messaging_person = person;
        text = text_constr;
    }
    Message(const Message& copy) = default;
    Message& operator = (Message to_copy) {
        std::swap(messaging_person, to_copy.messaging_person);
        std::swap(text, to_copy.text);
        return (*this);
    }
    ~Message() = default;
};

class Chat {
private:
// TODO: put all public into private
    std::string chat_name;
    std::string all_chat;
    std::set<std::string> people_in_chat;
    std::vector<Message> messages;
public:
    Chat() = default;
    ~Chat() = default;
    Chat(const Chat& to_copy) = default;
    Chat& operator = (Chat to_copy) {
        std::swap(messages, to_copy.messages);
        std::swap(all_chat, to_copy.all_chat);
        std::swap(chat_name, to_copy.chat_name);
        std::swap(people_in_chat, to_copy.people_in_chat);
        return (*this);
    }
    explicit Chat(const std::vector<std::string>& names) {};
    explicit Chat(const std::string& chat_name_const, const std::set<std::string>& people_in_chat_constr) {
        chat_name = chat_name_const;
        messages = std::vector<Message>();
        people_in_chat = people_in_chat_constr;
        all_chat = "";
    }
    [[nodiscard]] std::string get_name() const {
        return chat_name;
    }
    void Add_Message(const std::string& message, const std::string& messaging_person) {
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
    [[nodiscard]] std::string get_all_chat() const {
        return all_chat;
    }
    [[nodiscard]] size_t get_size() const {
        return messages.size();
    }
    std::string get_last_n_messages(int number) {
        std::string ans;
        if (number > messages.size()) {
            return all_chat;
        }
        for (int i = static_cast<int>(messages.size()) - number; i < messages.size(); ++i) {
            ans += messages[i].messaging_person + ": " + messages[i].text + "\n\n";
        }
        return ans;
    }

    friend class ChatDataHandler;
};