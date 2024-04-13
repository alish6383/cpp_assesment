#include <iostream>
using namespace std;

class School {
private:
    string name;
public:
    School(string n) {
        name = n;
    }
    virtual ~School() {}
    virtual void show() {
        cout << "School: " << name << endl;
    }
};

class Programming : virtual public School {
private:
    int numCourses;
public:
    Programming(string n, int courses) : School(n) {
        numCourses = courses;
    }
    void show() {
        School::show();
        cout << "Programming Courses: " << numCourses << endl;
    }
};

class Network : virtual public School {
private:
    int numCourses;
public:
    Network(string n, int courses) : School(n) {
        numCourses = courses;
    }
    void show() {
        School::show();
        cout << "Network Courses: " << numCourses << endl;
    }
};

class Student : public Programming, public Network {
private:
    string studentName;
    int studentCode;
public:
    Student(string schoolName, string name, int code, int progCourses, int netCourses)
        : School(schoolName), Programming(schoolName, progCourses), Network(schoolName, netCourses) {
        studentName = name;
        studentCode = code;
    }
    void show() {
        School::show();
        cout << "Student Name: " << studentName << endl;
        cout << "Student Code: " << studentCode << endl;
    }
};

int main() {
    string schoolName, studentName;
    int studentCode, progCourses, netCourses;

    cout << "Enter the school name: ";
    getline(cin, schoolName);
    cout << "Enter the student name: ";
    getline(cin, studentName);
    cout << "Enter the student code: ";
    cin >> studentCode;
    cout << "Enter the number of programming courses: ";
    cin >> progCourses;
    cout << "Enter the number of network courses: ";
    cin >> netCourses;

    Student s(schoolName, studentName, studentCode, progCourses, netCourses);

    School& p = s;
    p.show();

    return 0;
}
