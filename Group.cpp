#include "libs.h"

class Group {
private:
    long long id;
    std::string name;
    std::string tutor_name;
    std::vector <std::string> students_names;
    std::map <std::string, Task> tasks;
public:

    Group(long long id, const std::string &name, const std::string &tutor_name,
          std::vector <std::string> students_names) :
            id(id), name(name), tutor_name(tutor_name), students_names(students_names) {}
    ~Group() = default;

    std::string info() {
        std::string block_students;
        for (auto s: students_names) {
            block_students += s + "\n";
        }
        if (students_names.empty()) {
            block_students = "None\n";
        }
        std::string block_tasks;
        for (auto p: tasks) {
            block_tasks += p.first + "\n";
        }
        if (tasks.empty()) {
            block_tasks = "None\n";
        }
        std::string text = "Group's name: " + name + "\nTutor's name: " + tutor_name +
                           "\nStudents:\n" + block_students + "\nTasks: " + block_tasks;

        return text;
    }

};
