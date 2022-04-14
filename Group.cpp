#include "library.h"
#include "Task.cpp"

class Group {
private:
    long long id;
    std::string name;
    std::string tutor_name;
public:
    std::vector<std::string> students_names;
    std::map<std::string, Task> tasks;

    Group() = default; // смотря как ты хочешь заполнять группу и работать с id
    Group(const Group& copy) = default;
    Group& operator= (const Group& copy) = default;
    ~Group() = default;

    const long long& get_id() {
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
        tasks[task_name] = Task(task_name, task_problem, tutor_name, student_name);
    }
    Task* get_task(const std::string& task_name) {
        return &tasks[task_name];
    }
    void close_task(const std::string& task_name) {
        tasks[task_name].close();
    }
    const std::vector<std::string>& get_students() {
        return students_names;
    }
    const std::string& get_tutor() {
        return tutor_name;
    }
};