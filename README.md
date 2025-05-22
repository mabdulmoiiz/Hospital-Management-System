# 🏥 Hospital Management System (C++)

A console-based hospital management system designed to streamline patient management, appointment scheduling, and medical record keeping. This project utilizes object-oriented programming principles such as constructors, member functions, access modifiers, and inheritance.

---

## 📌 Project Requirements

**Objective**:  
Develop a hospital management system to:
- Streamline **patient management**
- Enable **appointment scheduling**
- Support **medical record keeping**

**Implementation Goals**:
- Use of **classes**: Patient, Doctor, Appointment, MedicalRecord
- Demonstrate:
  - Constructors
  - Member functions
  - Access modifiers (private/protected/public)
  - Inheritance (e.g., Doctor and Patient inherit from Person)

---

## 💡 Key Features

- 👨‍⚕️ Add and manage **Patient** and **Doctor** records
- 📆 Book and view **Appointments**
- 📋 Maintain and access **Medical Records**
- 🔐 Role-based access: Admin (full control), Doctor (read-only)
- 🧱 Structured using C++ **OOP principles**

---

## 🧪 Login Credentials

| Role    | Username | Password   |
|---------|----------|------------|
| Admin   | `admin`  | `admin123` |
| Doctor  | `doctor` | `doctor123` |

---

## ⚙️ How to Compile and Run

### Prerequisites:
- A C++ compiler (e.g., `g++`)
- C++11 or later

### Instructions:

```bash
# Compile
g++ hospital.cpp -o hospital

# Run
./hospital
