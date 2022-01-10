#include <iostream>
#include <memory>

using namespace std;

class Project {
    string p_name;
public:
    void setName(const string &name) {
        p_name = name;
    }

    void ShowName() {
        cout << p_name << endl;
    }

    void ShowDetails() {
        cout << "details of project" << endl;
    }
};

class Employee {
private:
    shared_ptr<Project> p_id;
public:
    void setProject(const shared_ptr<Project> &p) {
        p_id = p;
    }
};

int main() {
    shared_ptr<Project> pr {new Project};
    pr->setName("hello world");

    Employee e1;
    e1.setProject(pr);

    Employee e2;
    e2.setProject(pr);

    pr->ShowDetails();

    pr->ShowName();

    return 0;
}
