#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;
};

vector<Student> students;

// Add Student
void addStudent() {
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "Student Added Successfully!\n";
}

// Display Students
void displayStudents() {

    if (students.empty()) {
        cout << "\nNo Records Found!\n";
        return;
    }

    cout << "\nStudent Records\n";
    cout << "-----------------------------------\n";

    for (auto s : students) {
        cout << "Roll No: " << s.rollNo << endl;
        cout << "Name    : " << s.name << endl;
        cout << "Marks   : " << s.marks << endl;
        cout << "---------------------------\n";
    }
}

// Bubble Sort by Marks
void sortStudents() {

    int n = students.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (students[j].marks < students[j + 1].marks) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "\nStudents Sorted By Marks (Descending)\n";
}

// Linear Search by Roll Number
void searchStudent() {

    int roll;
    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    bool found = false;

    for (auto s : students) {

        if (s.rollNo == roll) {

            cout << "\nStudent Found!\n";
            cout << "Roll No: " << s.rollNo << endl;
            cout << "Name   : " << s.name << endl;
            cout << "Marks  : " << s.marks << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent Not Found!\n";
}

int main() {

    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Sort Students By Marks\n";
        cout << "4. Search Student By Roll Number\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            sortStudents();
            break;

        case 4:
            searchStudent();
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
