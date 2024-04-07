#include <iostream>
 using namespace std;

const int MAX_STUDENTS = 100;

int addStudents() {
    int numStudents;
    cout << "Enter the number of students in the class: ";
    cin >> numStudents;

    while (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        cout << "Invalid input. Please enter a positive number of students (up to " << MAX_STUDENTS << "): ";
        cin >> numStudents;
    }

    return numStudents;
}

void markAttendance(char attendance[], int numStudents) {
    cout << "Mark attendance for each student (a for absent, p for present):" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> attendance[i];
        // Validate input
        while (attendance[i] != 'a' && attendance[i] != 'p') {
            cout << "Invalid input. Please enter 'a' for absent or 'p' for present: ";
            cin >> attendance[i];
        }
    }
}

void displayAttendance(const char attendance[], int numStudents) {
    int presentCount = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (attendance[i] == 'p')
            presentCount++;
    }

    double attendancePercentage = static_cast<double>(presentCount) / numStudents * 100;

    cout << "Overall Attendance Percentage: " << attendancePercentage << "%" << endl;
}

int main() {
    char attendance[MAX_STUDENTS];
    int numStudents = addStudents();

    for (int i = 0; i < numStudents; ++i) {
        attendance[i] = 'a';
    }

    int choice;
    do {
        cout << "\n      Menu " << endl;
        cout << "1. Mark Attendance" << endl;
        cout << "2. Display Attendance Percentage" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                markAttendance(attendance, numStudents);
                break;
            case 2:
                displayAttendance(attendance, numStudents);
                break;
            case 3:
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
