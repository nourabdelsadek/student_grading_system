#include <bits/stdc++.h>
using namespace std;

class IFileOperations {
public:
    virtual void saveData() = 0;
    virtual void loadData() = 0;
};

class Student {
private:
    string name;
    int id;
    float grade;

public:
    Student(string name, int id, float grade) : name(name), id(id), grade(grade) {}

    int getID() const { return id; }
    float getGrade() const { return grade; }
    string getName() const { return name; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Grade: " << grade << endl;
    }

    void updateInfo(const string& newName, float newGrade) {
        name = newName;
        grade = newGrade;
    }
};

class StudentManager : public IFileOperations {
private:
    vector<Student> students;
    int binarySearch(int id) const {
        int l = 0;
        int r = students.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (students[mid].getID() == id) {
                return mid;
            }
            else if (students[mid].getID() < id) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }

public:
    void addStudent(const Student& student) {
        students.push_back(student);
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.getID() < b.getID();
        });
    }

    void displayAll() const {
        for (const auto& student : students) {
            student.display();
        }
    }

    Student* searchByID(int id) {
        int index = binarySearch(id);
        return (index != -1) ? &students[index] : nullptr;
    }

    Student* searchByName(const string& name) {
        for (auto& student : students) {
            if (student.getName() == name) {
                return &student;
            }
        }
        return nullptr;
    }

    void updateStudent(int id, const string& newName, float newGrade) {
        Student* student = searchByID(id);
        if (student) {
            student->updateInfo(newName, newGrade);
            cout << "Student information updated successfully.\n";
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    void deleteStudent(int id) {
        auto it = remove_if(students.begin(), students.end(), [&](const Student& student) {
            return student.getID() == id;
        });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student with ID " << id << " deleted successfully.\n";
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    float calculateAverageGrade() const {
        if (students.empty()) return 0.0;
        float total = accumulate(students.begin(), students.end(), 0.0f,
            [](float sum, const Student& student) { return sum + student.getGrade(); });
        return total / students.size();
    }

    void displayStatistics() const {
        if (students.empty()) {
            cout << "No students available for statistics.\n";
            return;
        }
        float maxGrade = students[0].getGrade();
        float minGrade = students[0].getGrade();
        for (const auto& student : students) {
            if (student.getGrade() > maxGrade) maxGrade = student.getGrade();
            if (student.getGrade() < minGrade) minGrade = student.getGrade();
        }
        cout << "Highest Grade: " << maxGrade << endl;
        cout << "Lowest Grade: " << minGrade << endl;
    }

    void displayStudentsNeedingEnhancements() const {
        cout << "Students with grades less than 50%:\n";
        bool found = false;
        for (const auto& student : students) {
            if (student.getGrade() < 50.0) {
                student.display();
                found = true;
            }
        }
        if (!found) {
            cout << "No students found needing enhancements.\n";
        }
    }

    void loadStudentsFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;
        }
        string name;
        int id;
        float grade;
        while (file >> id >> name >> grade) {
            addStudent(Student(name, id, grade));
        }
        file.close();
        cout << "Students loaded successfully from " << filename << ".\n";
    }

    void saveData() override {
        ofstream file("students.txt");
        for (const auto& student : students) {
            file << student.getID() << " " << student.getName() << " " << student.getGrade() << endl;
        }
        file.close();
    }

    void loadData() override {
        ifstream file("input.txt");
        string name;
        int id;
        float grade;
        while (file >> id >> name >> grade) {
            addStudent(Student(name, id, grade));
        }
        file.close();
    }
};

class StudentApp {
private:
    StudentManager manager;

    void displayMenu() {
        cout << "========== Student Record Management =========="<<endl;
        cout << "1. Add Student"<<endl;
        cout << "2. Display All Students"<<endl;
        cout << "3. Search for Student by ID"<<endl;
        cout << "4. Search for Student by Name"<<endl;
        cout << "5. Update Student Information"<<endl;
        cout << "6. Delete Student Record"<<endl;
        cout << "7. Calculate Average Grade"<<endl;
        cout << "8. Display Grade Statistics"<<endl;
        cout << "9. Display Students Needing Enhancements"<<endl;
        cout << "10. Load Students from input.txt"<<endl;
        cout << "11. Exit\n";
        cout << "==============================================="<<endl;
        cout << "Choose an option: ";
    }

    void addStudent() {
        string name;
        int id;
        float grade;
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Grade: ";
        cin >> grade;

        manager.addStudent(Student(name, id, grade));
        cout << "Student added successfully."<<endl;
    }

    void searchStudentByID() {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;
        Student* student = manager.searchByID(id);
        if (student) {
            student->display();
        } else {
            cout << "Student with ID " << id << " not found."<<endl;
        }
    }

    void searchStudentByName() {
        string name;
        cout << "Enter Student Name to search: ";
        cin >> name;
        Student* student = manager.searchByName(name);
        if (student) {
            student->display();
        } else {
            cout << "Student with Name " << name << " not found."<<endl;
        }
    }

    void updateStudent() {
        int id;
        string newName;
        float newGrade;
        cout << "Enter Student ID to update: ";
        cin >> id;
        cout << "Enter new Name: ";
        cin >> newName;
        cout << "Enter new Grade: ";
        cin >> newGrade;

        manager.updateStudent(id, newName, newGrade);
    }

    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;
        manager.deleteStudent(id);
    }

    void calculateAverageGrade() {
        float avg = manager.calculateAverageGrade();
        cout << "Average Grade: " << avg << endl;
    }

    void displayStatistics() {
        manager.displayStatistics();
    }

    void displayStudentsNeedingEnhancements() {
        manager.displayStudentsNeedingEnhancements();
    }

    void loadStudentsFromFile() {
        manager.loadStudentsFromFile("input.txt");
    }

public:
    void run() {
        int c = 0;
        while (c != 11) {
            displayMenu();
            cin >> c;
            if(c==1)
                    addStudent();
            else if(c==2)
                    manager.displayAll();
            else if(c==3)
                    searchStudentByID();
            else if(c==4)
                    searchStudentByName();
            else if(c==5)
                    updateStudent();
            else if(c==6)
                    deleteStudent();
            else if(c==7)
                    calculateAverageGrade();
            else if(c==8)
                    displayStatistics();
            else if(c==9)
                    displayStudentsNeedingEnhancements();
            else if(c==10)
                    loadStudentsFromFile();
            else if(c==11){
                    manager.saveData();
                    cout << "Exiting program. Data saved."<<endl;
                }
            else
                    cout << "Invalid choice. Please try again."<<endl;
        }
    }
};

int main() {
    StudentApp app;
    app.run();
    return 0;
}
