#include <iostream>
using namespace std;

class Student {
private:
    int code;
    int courses;
    float *grd;

public:
    Student(int c = 0, int crs = 0) : code(c), courses(crs) {
        grd = new float[courses];
    }

    ~Student() {
        delete[] grd;
    }

    void inputDetails() {
        cout << "Enter student code: ";
        cin >> code;
        cout << "Enter number of courses: ";
        cin >> courses;
        grd = new float[courses];
        cout << "Enter grades for each course:\n";
        for (int i = 0; i < courses; ++i) {
            cout << "Grade for course " << (i + 1) << ": ";
            cin >> grd[i];
        }
    }

    friend int operator>(Student& s1, Student& s2) {
        int passedCoursesS1 = 0, passedCoursesS2 = 0;
        for (int i = 0; i < s1.courses; ++i)
            if (s1.grd[i] >= 5)
                passedCoursesS1++;
        for (int i = 0; i < s2.courses; ++i)
            if (s2.grd[i] >= 5)
                passedCoursesS2++;
        if (passedCoursesS1 > passedCoursesS2)
            return 1;
        else if (passedCoursesS2 > passedCoursesS1)
            return 2;
        else
            return 3;
    }

    Student& operator=(Student&) = delete;

    void getCodeAndCourses(int& c, int& crs) const {
        c = code;
        crs = courses;
    }
};

int main() {
    int i;
    Student s1, s2;

    cout << "Enter details for student 1:\n";
    s1.inputDetails();

    cout << "\nEnter details for student 2:\n";
    s2.inputDetails();

    i = (s1 > s2);

    int codeS1, codeS2, coursesS1, coursesS2;
    s1.getCodeAndCourses(codeS1, coursesS1);
    s2.getCodeAndCourses(codeS2, coursesS2);

    if (i == 1)
        cout << "\nStudent " << codeS1 << " has succeeded in more courses.\n";
    else if (i == 2)
        cout << "\nStudent " << codeS2 << " has succeeded in more courses.\n";
    else
        cout << "\nBoth students have succeeded in the same number of courses.\n";

    return 0;
}
