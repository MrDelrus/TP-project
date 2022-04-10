#include "libs.h"

class Task {
private:
    bool is_open;
    std::string name;
    std::string problem;
    std::string tutor;
    std::string student;
    Chat discussion;
public:
    Task(const std::string& name, const std::string& problem,
          const std::string& tutor_name, const std::string& student_name):
            is_open(true), name(name), problem(problem), tutor(tutor_name), student(student_name) /*, discussion(Chat()) */ {}
    ~Task() = default;

    std::string info() {
        std::string text = "Task: " + name + "\nTutor: " +
                tutor + "\nStudent: " + student + "\nProblem:\n" + problem;
        return text;
    }
};