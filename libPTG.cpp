#pragma once
#include <string>
#include <utility>
#include <vector>
#include "Chat.cpp"
#include "libST.cpp"
#include <set>
#include <map>
 
class Problem {
private:
    Tutor* tutor;
    std::string name;
    std::string data;
public:
    Problem(Tutor* tutor, std::string n, std::string  t): tutor(tutor), name(std::move(n)), data(std::move(t)) {}
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
    std::string name;
    Tutor* tutor;
    Problem data;
    std::set<Student*> students;
    std::map<Student*, Chat*> personal_discussions;
public:
    Task(std::string name, Tutor* tutor_constr, const Problem& problem, const std::set<Student*>& students = std::set<Student*>()):
    name(name), data(problem), students(students) {
        for (auto s: students) {
            std::string name = tutor->GetName() + " " + s->GetName();
            personal_discussions[s] = new Chat(name, std::set<Person*>({tutor, s}));
        }
    }
    Task(const Task&) = default;
    ~Task() = default;
 
    std::set<Student*> GetStudents() {
        return students;
    }
 
    void AddStudent(Student* student) {
        students.insert(student);
        std::string chat_name = tutor->GetName() + " " + student->GetName();
        personal_discussions[student] = new Chat(chat_name, std::set<Person*>({tutor, student}));
    }
 
    void EraseStudent(Student* student) {
        students.erase(student);
        personal_discussions.erase(student);
    }
 
    Chat* GetChat(Student* student) {
        return personal_discussions[student];
    }
 
    bool operator < (const Task& to_compare) const {
        return name < to_compare.name;
    }
};
 
class Group {
private:
    Tutor* tutor;
    std::set<Student*> students;
    std::set<Task*> tasks;
    std::string table;
    std::string name;
    int id;
public:
 
    Group(Tutor* tutor, const std::string& name, int id_constr, std::set<Student*> students = std::set<Student*>()) :
    tutor(tutor), students(students), name(name), id(id_constr) {}
    Group(const Group&) = default;
    ~Group() = default;
 
    [[nodiscard]] const std::string GetName() const {
        return name;
    }

    [[nodiscard]] const int GetId() const {
        return id;
    }

    std::set<Student*> GetStudents() {
        return students;
    }
 
    std::string GetLink() {
        //frontend?
    }
 
    void AddTask(Task& task) {
        tasks.insert(&task);
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
