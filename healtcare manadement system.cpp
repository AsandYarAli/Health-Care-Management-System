#include <iostream>
#include <vector>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string diagnosis;
};

vector<Patient> patients;

void addPatient() {
    Patient p;
    p.id = patients.size() + 1;
    cout << "Enter name, age, and diagnosis: ";
    cin >> p.name >> p.age >> p.diagnosis;
    patients.push_back(p);
    cout << "Patient added!\n";
}

void viewPatients() {
    if (patients.empty()) cout << "No patients found.\n";
    else for (auto& p : patients)
        cout << "ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << ", Diagnosis: " << p.diagnosis << "\n";
}

void deletePatient() {
    int id;
    cout << "Enter patient ID to delete: ";
    cin >> id;
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->id == id) {
            patients.erase(it);
            cout << "Patient deleted!\n";
            return;
        }
    }
    cout << "Patient not found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Patient\n2. View Patients\n3. Delete Patient\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addPatient();
        else if (choice == 2) viewPatients();
        else if (choice == 3) deletePatient();
        else if (choice == 4) break;
        else cout << "Invalid choice!\n";
    }
    return 0;
}
