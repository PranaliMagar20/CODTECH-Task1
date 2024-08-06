#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    vector<float> grades;

    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void addGrade(float grade) {
        grades.push_back(grade);
    }

    float calculateAverageGrade() {
        if (grades.empty()) {
            return 0;
        }
        float sum = 0;
        for (float grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Average Grade: " << calculateAverageGrade() << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;
    int nextId = 1;

    Student* findStudentById(int id) {
        for (auto &student : students) {
            if (student.id == id) {
                return &student;
            }
        }
        return nullptr;
    }

public:
    void addStudent(string name) {
        students.push_back(Student(nextId++, name));
        cout << "Student added successfully." << endl;
    }

    void editStudent(int id, string newName) {
        Student* student = findStudentById(id);
        if (student) {
            student->name = newName;
            cout << "Student information updated successfully." << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully." << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void addGrade(int id, float grade) {
        Student* student = findStudentById(id);
        if (student) {
            student->addGrade(grade);
            cout << "Grade added successfully." << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    void displayStudent(int id) {
        Student* student = findStudentById(id);
        if (student) {
            student->display();
        } else {
            cout << "Student not found!" << endl;
        }
    }

    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students to display." << endl;
            return;
        }
        for (Student &student : students) {
            student.display();
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;
    string name;
    int id;
    float grade;

    do {
        cout << "\n1. Add Student\n2. Edit Student\n3. Delete Student\n4. Add Grade\n5. Display Student\n6. Display All Students\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> ws; // to consume the newline character
                getline(cin, name);
                sms.addStudent(name);
                break;
            case 2:
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter new student name: ";
                cin >> ws;
                getline(cin, name);
                sms.editStudent(id, name);
                break;
            case 3:
                cout << "Enter student ID: ";
                cin >> id;
                sms.deleteStudent(id);
                break;
            case 4:
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter grade: ";
                cin >> grade;
                sms.addGrade(id, grade);
                break;
            case 5:
                cout << "Enter student ID: ";
                cin >> id;
                sms.displayStudent(id);
                break;
            case 6:
                sms.displayAllStudents();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
