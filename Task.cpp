#include <utility>

#include "library.h"
#include "Chat.cpp"

class Task {
private:
    bool is_open;
    std::string name;
    std::string problem;
    std::string tutor;
    std::string student;
    Chat discussion;
public:
    Task(std::string name, std::string problem, const std::string& tutor_name, const std::string& student_name):
            is_open(true), name(std::move(name)), problem(std::move(problem)), tutor(tutor_name), student(student_name),
            discussion(Chat(std::vector<std::string>({tutor_name, student_name}))) {};
    Task(const Task& copy) = default;
    Task& operator= (const Task& copy) = default;
    ~Task() = default;

    std::string get_info() {
        return "Task: " + name + "\nTutor: " + tutor + "\nStudent: " + student + "\nProblem:\n" + problem;
    }
    void change_problem(const std::string& new_problem) {
        problem = new_problem;
    }
    Chat* get_discussion() {
        return &discussion;
    }
    void close() {
        is_open = false;
    }
};