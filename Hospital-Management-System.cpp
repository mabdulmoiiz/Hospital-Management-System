#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Header
void showHeader() {
    cout << "\n==============================\n"
         << "  HOSPITAL MANAGEMENT SYSTEM\n"
         << "==============================\n";
}

// Class Definitions
class Person {
protected:
    string name, gender;
    int age;

public:
    Person() {}
    Person(string n, int a, string g) : name(n), age(a), gender(g) {}

    virtual void display() const {
        cout << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << endl;
    }
};

class Patient : public Person {
    int id;
    string disease;

public:
    Patient() {}
    Patient(int pid, string n, int a, string g, string dis)
        : Person(n, a, g), id(pid), disease(dis) {}

    void display() const override {
        cout << "\n[Patient Info]\n";
        Person::display();
        cout << "Patient ID: " << id << "\nDisease: " << disease << endl;
    }

    int getId() const { return id; }
};

class Doctor : public Person {
    int id;
    string specialization;

public:
    Doctor() {}
    Doctor(int did, string n, int a, string g, string spec)
        : Person(n, a, g), id(did), specialization(spec) {}

    void display() const override {
        cout << "\n[Doctor Info]\n";
        Person::display();
        cout << "Doctor ID: " << id << "\nSpecialization: " << specialization << endl;
    }

    int getId() const { return id; }
};

class Appointment {
    int patientId, doctorId;
    string date, time, disease;

public:
    Appointment() {}
    Appointment(int pid, int did, string d, string t, string dis)
        : patientId(pid), doctorId(did), date(d), time(t), disease(dis) {}

    void display() const {
        cout << "\n[Appointment Info]\n"
             << "Patient ID: " << patientId << "\nDoctor ID: " << doctorId
             << "\nDate: " << date << "\nTime: " << time << "\nDisease: " << disease << endl;
    }
};

class MedicalRecord {
    int patientId;
    string diagnosis, treatment;

public:
    MedicalRecord() {}
    MedicalRecord(int pid, string diag, string treat)
        : patientId(pid), diagnosis(diag), treatment(treat) {}

    void display() const {
        cout << "\n[Medical Record]\n"
             << "Patient ID: " << patientId
             << "\nDiagnosis: " << diagnosis
             << "\nTreatment: " << treatment << endl;
    }
};

// HospitalManagementSystem Class
class HospitalManagementSystem {
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    vector<MedicalRecord> records;

public:
    void insertPatient() {
        int id, age;
        string name, gender, disease;
        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
        patients.push_back(Patient(id, name, age, gender, disease));
        cout << "Patient added successfully.\n";
    }

    void insertDoctor() {
        int id, age;
        string name, gender, specialization;
        cout << "Enter Doctor ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Specialization: ";
        cin.ignore();
        getline(cin, specialization);
        doctors.push_back(Doctor(id, name, age, gender, specialization));
        cout << "Doctor added successfully.\n";
    }

    void createAppointment() {
        int pid, did;
        string date, time, disease;
        cout << "Enter Patient ID: ";
        cin >> pid;
        cout << "Enter Doctor ID: ";
        cin >> did;
        cout << "Enter Date (DD-MM-YYYY): ";
        cin >> date;
        cout << "Enter Time (HH:MM): ";
        cin >> time;
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
        appointments.push_back(Appointment(pid, did, date, time, disease));
        cout << "Appointment created.\n";
    }

    void createRecord() {
        int pid;
        string diagnosis, treatment;
        cout << "Enter Patient ID: ";
        cin >> pid;
        cout << "Enter Diagnosis: ";
        cin.ignore();
        getline(cin, diagnosis);
        cout << "Enter Treatment: ";
        getline(cin, treatment);
        records.push_back(MedicalRecord(pid, diagnosis, treatment));
        cout << "Medical record created.\n";
    }

    void displayPatients() const {
        if (patients.empty()) {
            cout << "No patients available.\n";
            return;
        }
        for (const auto &p : patients)
            p.display();
    }

    void displayDoctors() const {
        if (doctors.empty()) {
            cout << "No doctors available.\n";
            return;
        }
        for (const auto &d : doctors)
            d.display();
    }

    void displayAppointments() const {
        if (appointments.empty()) {
            cout << "No appointments scheduled.\n";
            return;
        }
        for (const auto &a : appointments)
            a.display();
    }

    void displayRecords() const {
        if (records.empty()) {
            cout << "No medical records found.\n";
            return;
        }
        for (const auto &r : records)
            r.display();
    }
};

// Login
string login() {
    string username, password;
    cout << "\nLogin\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == "admin" && password == "admin123")
        return "admin";
    else if (username == "doctor" && password == "doctor123")
        return "doctor";
    else
        return "invalid";
}

// Main
int main() {
    showHeader();
    HospitalManagementSystem hms;

    while (true) {
        string role = login();

        if (role == "invalid") {
            cout << "!! Invalid credentials. Try again.\n";
            continue;
        }

        int choice;

        if (role == "admin") {
            do {
                cout << "\n--- Admin Menu ---\n"
                     << "1. Add Patient\n"
                     << "2. Add Doctor\n"
                     << "3. Create Appointment\n"
                     << "4. Create Medical Record\n"
                     << "5. View Patients\n"
                     << "6. View Doctors\n"
                     << "7. View Appointments\n"
                     << "8. View Medical Records\n"
                     << "9. Logout\n"
                     << "0. Exit\n"
                     << "Choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case 1: hms.insertPatient(); break;
                    case 2: hms.insertDoctor(); break;
                    case 3: hms.createAppointment(); break;
                    case 4: hms.createRecord(); break;
                    case 5: hms.displayPatients(); break;
                    case 6: hms.displayDoctors(); break;
                    case 7: hms.displayAppointments(); break;
                    case 8: hms.displayRecords(); break;
                    case 9: cout << "Logging out...\n"; goto relogin;
                    case 0: cout << "Goodbye!\n"; return 0;
                    default: cout << "Invalid choice.\n";
                }
            } while (true);
        } else if (role == "doctor") {
            do {
                cout << "\n--- Doctor Menu (View Only) ---\n"
                     << "1. View Patients\n"
                     << "2. View Doctors\n"
                     << "3. View Appointments\n"
                     << "4. View Medical Records\n"
                     << "5. Logout\n"
                     << "0. Exit\n"
                     << "Choice: ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (choice) {
                    case 1: hms.displayPatients(); break;
                    case 2: hms.displayDoctors(); break;
                    case 3: hms.displayAppointments(); break;
                    case 4: hms.displayRecords(); break;
                    case 5: cout << "Logging out...\n"; goto relogin;
                    case 0: cout << "Goodbye!\n"; return 0;
                    default: cout << "Invalid choice.\n";
                }
            } while (true);
        }

    relogin:
        continue;
    }

    return 0;
}

