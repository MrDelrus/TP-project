#include "libs.h"

std::string Group::get_info() {
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
