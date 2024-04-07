#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Patient {
public:
    string id;
    char disease;
    string treatment;
    char newPatient;
    int tokenNumber;
    string dateofVisit;

    Patient(string id, char disease, string treatment, char newPatient, int tokenNumber, string dateofVisit) {
        this->id = id;
        this->disease = disease;
        this->treatment = treatment;
        this->newPatient = newPatient;
        this->tokenNumber = tokenNumber;
        this->dateofVisit = dateofVisit;
    }
};

class Hospital {
private:
    map<string, queue<Patient>> departmentQueues;

public:
    void addPatientToQueue(string department, Patient patient) {
        departmentQueues[department].push(patient);
        patient.tokenNumber = departmentQueues[department].size();
    }

    int totalPatientsInQueue(string department) {
        return departmentQueues[department].size();
    }

    int patientsWaiting() {
        int totalWaiting = 0;
        for (auto& department : departmentQueues) {
            totalWaiting += department.second.size();
        }
        return totalWaiting;
    }

    void displayAllPatients() {
        cout << "Patients in all departments:" << endl;
        for (auto& department : departmentQueues) {
            cout << "Department: " << department.first << endl;
            queue<Patient>& departmentQueue = department.second;
            while (!departmentQueue.empty()) {
                Patient patient = departmentQueue.front();
                departmentQueue.pop();
                cout << "ID: " << patient.id << ", Disease: " << patient.disease << ", Treatment: " << patient.treatment
                     << ", New Patient: " << patient.newPatient << ", Token Number: " << patient.tokenNumber
                     << ", Date of Visit: " << patient.dateofVisit << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    Hospital hospital;
    int totalDays = 1;
    while (true) {
        cout << "\nHospital Management System" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Total Number of Patients in a Department Queue" << endl;
        cout << "3. Total Number of Patients Waiting" << endl;
        cout << "4. Average Patients per Day" << endl;
        cout << "5. Display All Patients in All Departments" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice:";
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1: {
                string id, treatment, dateofVisit;
                char disease, newPatient;
                int tokenNumber = 0;

                cout << "Enter patient ID: ";
                cin >> id;
                cout << "Enter disease (single character): ";
                cin >> disease;
                cout << "Enter prescribed treatment: ";
                cin >> treatment;
                cout << "Is the patient new? (Y/N): ";
                cin >> newPatient;
                cout << "Enter date of visit (YYYY-MM-DD): ";
                cin >> dateofVisit;

                string department;
                cout << "Enter department: ";
                cin >> department;

                Patient newPatientObject(id, disease, treatment, newPatient, tokenNumber, dateofVisit);
                hospital.addPatientToQueue(department, newPatientObject);
                cout << "Patient added successfully!" << endl;
                break;
            }
            case 2: {
                string department;
                cout << "Enter department: ";
                cin >> department;
                cout << "Total patients in " << department << " queue: " << hospital.totalPatientsInQueue(department) << endl;
                break;
            }
            case 3: {
                cout << "Total patients waiting: " << hospital.patientsWaiting() << endl;
                break;
            }
            case 4: {
                cout << "Average patients per day: " << static_cast<double>(hospital.patientsWaiting()) / totalDays << endl;
                break;
            }
            case 5: {
                hospital.displayAllPatients();
                break;
            }
            case 6: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
