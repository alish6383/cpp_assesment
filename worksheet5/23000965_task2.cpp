#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee {
    char name[150];
    int tax_number;
    float salary;
};

const int MAX_EMPLOYEES = 50;
void readEmployeeData(Employee employees[], int& num_employees);
void writeEmployeeData(Employee employees[], int num_employees);
void copyFilteredData(float min_salary);

void readEmployeeData(Employee employees[], int& num_employees) {
    cout << "Enter employee data:\n";
    while (num_employees < MAX_EMPLOYEES) {
        cout << "Employee " << num_employees + 1 << ":\n";

        cout << "Name: ";
        cin >> employees[num_employees].name;
        if (strcmp(employees[num_employees].name, "fin") == 0) {
            break;
        }

        cout << "Tax Number: ";
        cin >> employees[num_employees].tax_number;

        cout << "Salary: ";
        cin >> employees[num_employees].salary;

        num_employees++;
    }
    writeEmployeeData(employees, num_employees);
}

void writeEmployeeData(Employee employees[], int num_employees) {
    ofstream fout("test.bin", ios::binary);
    if (!fout) {
        cerr << "Error opening file" << endl;
        return;
    }
    fout.write(reinterpret_cast<const char*>(employees), sizeof(Employee) * num_employees);
    fout.close();
    cout << "Employee data written to test.bin successfully.\n";
}

void copyFilteredData(float min_salary) {
    ifstream fin("test.bin", ios::binary);
    if (!fin) {
        cerr << "Error opening file" << endl;
        return;
    }

    ofstream data_out("data.bin", ios::binary);
    if (!data_out) {
        cerr << "Error opening file" << endl;
        fin.close();
        return;
    }

    Employee emp;
    float total_salary = 0;
    int count = 0;
    while (fin.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.salary > min_salary) {
            data_out.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
            total_salary += emp.salary;
            count++;
        }
    }

    fin.close();
    data_out.close();

    if (count > 0) {
        float average_salary = total_salary / count;
        cout << "Filtered data copied to data.bin successfully.\n";
        cout << "Average salary of employees in data.bin: " << average_salary << endl;
    } else {
        cout << "No employees found with salary greater than " << min_salary << endl;
    }
}


int main() {
    int choice;
    float min_salary;

    do {
        cout << "Menu:\n";
        cout << "1. Read and store employee data\n";
        cout << "2. Filter and copy data\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee employees[MAX_EMPLOYEES];
                int num_employees = 0;
                readEmployeeData(employees, num_employees);
                break;
            }
            case 2:
                cout << "Enter minimum salary to filter employees: ";
                cin >> min_salary;
                copyFilteredData(min_salary);
                break;
            case 3:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}

