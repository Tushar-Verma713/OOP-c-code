#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string parentName;
    string regNo;
    int age;
    int semester;
    int rollNumber;
    int classesAttended;
    float marks[5];
    int totalClasses = 50;

public:
    // Function to input student details
    void getDetails() {
        cout << "Enter student's name: ";
        cin >> name;

        cout << "Enter parent's name: ";
        cin >> parentName;

        cout << "Enter registration number: ";
        cin >> regNo;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter semester: ";
        cin >> semester;

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter classes attended (out of 50): ";
        cin >> classesAttended;

        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    // Function to show all details of the student
    void showDetails() {
        cout << "\nRoll No: " << rollNumber << "\nName: " << name << "\nParent's Name: " << parentName
             << "\nRegistration Number: " << regNo << "\nAge: " << age << "\nSemester: " << semester
             << "\nClasses Attended: " << classesAttended << "/" << totalClasses << "\nMarks: ";
        for (int i = 0; i < 5; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    // Function to calculate and return attendance percentage
    float getAttendancePercentage() {
        return (classesAttended * 100) / totalClasses;
    }

    // Function to print attendance
    void printAttendance() {
        cout << "Roll No: " << rollNumber << ", Name: " << name << ", Attendance: " << getAttendancePercentage() << "%\n";
    }

    // Function to check and show attendance shortage
    void checkAttendanceShortage() {
        if (getAttendancePercentage() < 75) {
            cout << "Roll No: " << rollNumber << ", Name: " << name << " has attendance shortage.\n";
        } else {
            cout << "Roll No: " << rollNumber << ", Name: " << name << " has sufficient attendance.\n";
        }
    }

    // Function to calculate and return average marks
    float getAverageMarks() {
        float total = 0;
        for (int i = 0; i < 5; ++i) {
            total += marks[i];
        }
        return total / 5;
    }

    // Function to check if student has high average marks (90% or above)
    void checkHighAverageMarks() {
        if (getAverageMarks() >= 90) {
            cout << "Roll No: " << rollNumber << ", Name: " << name
                 << ", Average Marks: " << getAverageMarks() << " (90% or above)\n";
        }
    }

    // Getters for Roll Number and Name
    int getRollNumber() { return rollNumber; }
    string getName() { return name; }
};

// Function to display top 5 students based on average marks
void showTop5(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].getAverageMarks() < students[j + 1].getAverageMarks()) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "\nTop 5 Students (by average marks):\n";
    for (int i = 0; i < 5 && i < n; ++i) {
        cout << "Roll No: " << students[i].getRollNumber() << ", Name: " << students[i].getName()
             << ", Average Marks: " << students[i].getAverageMarks() << endl;
    }
}

int main() {
    int n;

    // Input number of students
    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];

    // Input details for each student
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].getDetails();
    }

    // Show details of all students
    cout << "\nDetails of all students:\n";
    for (int i = 0; i < n; ++i) {
        students[i].showDetails();
    }

    // Show attendance of all students
    cout << "\nAttendance of all students:\n";
    for (int i = 0; i < n; ++i) {
        students[i].printAttendance();
    }

    // Check attendance shortage for each student
    cout << "\nChecking attendance shortage (< 75%):\n";
    for (int i = 0; i < n; ++i) {
        students[i].checkAttendanceShortage();
    }

    // Show top 5 students based on marks
    showTop5(students, n);

    // Show students with 90% or more average marks
    cout << "\nStudents with 90% or more average marks:\n";
    for (int i = 0; i < n; ++i) {
        students[i].checkHighAverageMarks();
    }

    return 0;
}