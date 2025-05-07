//Problem Statemnet :
//Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. Display information of particular employee. If record of student does
//not exist an appropriate message is displayed. If it
//is, then the system displays the student details. Use sequential file to main the data.
//C++ Code :

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name, division, address;

    void getData() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();  // to clear newline from buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Division: ";
        getline(cin, division);
        cout << "Enter Address: ";
        getline(cin, address);
    }

    void showData() const {
        cout << "Roll No: " << roll << "\nName: " << name
             << "\nDivision: " << division << "\nAddress: " << address << "\n";
    }

    int getRoll() const {
        return roll;
    }
};

// Function to add student
void addStudent() {
    ofstream fout("students.txt", ios::app);
    Student s;
    s.getData();
    fout.write((char*)&s, sizeof(s));
    fout.close();
    cout << "Student added successfully.\n";
}

// Function to display a student by roll number
void searchStudent(int rollNo) {
    ifstream fin("students.txt", ios::in);
    Student s;
    bool found = false;

    while (fin.read((char*)&s, sizeof(s))) {
        if (s.getRoll() == rollNo) {
            cout << "\nRecord found:\n";
            s.showData();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student with Roll No " << rollNo << " not found.\n";

    fin.close();
}

// Function to delete a student by roll number
void deleteStudent(int rollNo) {
    ifstream fin("students.txt");
    ofstream fout("temp.txt");
    Student s;
    bool deleted = false;

    while (fin.read((char*)&s, sizeof(s))) {
        if (s.getRoll() != rollNo) {
            fout.write((char*)&s, sizeof(s));
        } else {
            deleted = true;
        }
    }

    fin.close();
    fout.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (deleted)
        cout << "Student with Roll No " << rollNo << " deleted.\n";
    else
        cout << "Student not found.\n";
}

// Main menu
int main() {
    int choice, rollNo;

    do {
        cout << "\n--- Student Record Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by Roll No\n";
        cout << "3. Delete Student by Roll No\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                searchStudent(rollNo);
                break;
            case 3:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteStudent(rollNo);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
