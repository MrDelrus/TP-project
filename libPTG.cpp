#include <string>
#include <vector>
#include "StudentTutorGroup.h"
#include "Chat.h"
#include <set>
 
class Problem {
private:
    Tutor* tutor;
    std::string name;
    std::string data;
public:
    Problem(Tutor* tutor, std::string n, const std::string& t): tutor(tutor), name(std::move(n)), data(t) {}
    Problem(const Problem&) = default;
    ~Problem() = default;
 
    Problem& ChangeText(const std::string& t) {
        this->data = t;
        return *this;
    }
 
    std::string& GetText() {
        return data;
    }
};
 
class Task {
private:
    Tutor tutor;
    Problem data;
    std::set<Student*> students;
    std::map<Student*, Chat*> discusses;
public:
    Task(Tutor tutor, const Problem& problem, const std::set<Student*>& students = std::set<Student*>()): data(problem), students(students) {
        for (auto s: students) {
            discussed[s] = Chat(std::set<Person*>(tutor, s));
        }
    }
    Task(const Task&) = default;
    ~Task() = default;
 
    std::set<Student*> GetStudents() {
        return students;
    }
 
    void AddStudent(const Student* student) {
        students.insert(student);
        discusses[student] = Chat(std::set<Person*>(tutor, student));
    }
 
    void EraseStudent(const Student* student) {
        students.erase(student);
        discusses.erase(student);
    }
 
    Chat* GetChat(Student* student) {
        return discussed[student];
    }
 
    bool operator < (const Task& to_compare) const {
        return Name < to_compare.Name;
    }
};
 
class Group {
private:
    Tutor* tutor;
    std::set<Student*> students;
    std::set<Task*> tasks;
    std::string table;
    std::string name;
public:
 
    Group(Tutor* tutor, std::set<Student*> students = std::set<Student*>(), const std::string& name) : tutor(tutor), students(students), name(name) {}
    Group(const Group&) = default;
    ~Group() = default;
 
    std::string GetName() {
        return name;
    }
 
    std::set<Student*> GetStudents() {
        return students;
    }
 
    std::string GetLink() {
        //frontend
    }
 
    void AddTask(const Task& task) {
        tasks.insert(*task);
    }
 
    std::set<Task*> GetTasks() {
        return tasks;
    }
 
    void SetTableLink(const std::string& link) {
        table = link;
    }
 
    std::string GetTableLink() {
        return table;
    }
 
};
 
#ifndef ATP_PROJECT_PROBLEMTASK_H
#define ATP_PROJECT_PROBLEMTASK_H
 
#endif //ATP_PROJECT_PROBLEMTASK_H
