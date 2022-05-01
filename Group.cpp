#pragma once
#include <cstdlib>
#include "library.h"
#include "Task.cpp"

class Group {
private:
    long long id = 0;
    std::string name;
    std::string tutor_name;
public:
    std::set<std::string> students_names;
    std::map<std::string, Task> tasks;

    Group() = default; // TODO: смотря как ты хочешь заполнять группу и работать с id
    Group(std::string name_c, std::string tutor_name_c, std::set<std::string> students_names_c) {
        name = std::move(name_c);
        tutor_name = std::move(tutor_name_c);
        students_names = std::move(students_names_c);
        id = 0;
        try {
            id = std::rand();
        }
        catch (const std::exception& e) {}
    }
    Group(std::string name_c, std::string tutor_name_c, std::set<std::string> students_names_c, long long id_c) {
        name = std::move(name_c);
        tutor_name = std::move(tutor_name_c);
        students_names = std::move(students_names_c);
        id = id_c;
    }
    Group(const Group& copy) = default;
    Group& operator = (const Group& copy) = default;
    ~Group() = default;

    std::string get_name() {
        return name;
    }

    long long get_id() {
        return id;
    }
    std::string get_info() {
        std::string block_students;
        for (const auto& s: students_names) {
            block_students += s + "\n";
        }
        if (students_names.empty()) {
            block_students = "None\n";
        }
        std::string block_tasks;
        for (const auto& p: tasks) {
            block_tasks += p.first + "\n";
        }
        if (tasks.empty()) {
            block_tasks = "None\n";
        }
        return "Group's name: " + name + "\nTutor's name: " + tutor_name +
                           "\nStudents:\n" + block_students + "\nTasks: " + block_tasks;
    }
    void add_task(const std::string& task_name, const std::string& task_problem, const std::string& student_name) {
        if (tasks.size() >= 32) {
            std::cout << "Number of tasks of the group should not be more than 32!\n";
            return;
        }
        tasks[task_name] = Task(task_name, task_problem, tutor_name, student_name);
    }
    void add_task(const Task& to_add) {
        if (tasks.size() >= 32) {
            std::cout << "Number of tasks of the group should not be more than 32!\n";
            return;
        }
        tasks[to_add.get_name()] = to_add;
    }
    Task* get_task(const std::string& task_name) {
        return &tasks[task_name];
    }
    void close_task(const std::string& task_name) {
        tasks[task_name].close();
    }
    const std::set<std::string>& get_students() {
        return students_names;
    }
    const std::string& get_tutor() {
        return tutor_name;
    }
    void add_student(const std::string& student_name) {
        students_names.insert(student_name);
    }

    friend class GroupParser;
};