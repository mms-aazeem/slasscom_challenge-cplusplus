#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int numBioClasses = 3;
const int numMathClasses = 5;
const int studentsPerClass = 40;
const int numSubjects = 3;

// Define a structure to represent a student
struct Student {
    string name;
    vector<int> marks;
    int totalMarks;
    int rank;
};

// Function to input marks for a student
void inputMarks(Student& student) {
    cout << "Enter marks for " << student.name << ":\n";
    for (int i = 0; i < numSubjects; ++i) {
        int mark;
        cout << "Subject " << i + 1 << " marks: ";
        cin >> mark;
        student.marks.push_back(mark);
    }
}

// Function to calculate total marks for a student
void calculateTotalMarks(Student& student) {
    student.totalMarks = 0;
    for (int mark : student.marks) {
        student.totalMarks += mark;
    }
}

// Function to compare two students based on total marks
bool compareStudents(const Student& s1, const Student& s2) {
    return s1.totalMarks > s2.totalMarks;
}

int main() {
    vector<Student> bioStudents;
    vector<Student> mathStudents;

    // Input marks for Bio stream students
    for (int classNum = 1; classNum <= numBioClasses; ++classNum) {
        for (int i = 1; i <= studentsPerClass; ++i) {
            Student student;
            cout << "Enter name of Bio student " << i << " in Class " << classNum << ": ";
            cin >> student.name;
            inputMarks(student);
            bioStudents.push_back(student);
        }
    }

    // Input marks for Math stream students
    for (int classNum = 1; classNum <= numMathClasses; ++classNum) {
        for (int i = 1; i <= studentsPerClass; ++i) {
            Student student;
            cout << "Enter name of Math student " << i << " in Class " << classNum << ": ";
            cin >> student.name;
            inputMarks(student);
            mathStudents.push_back(student);
        }
    }

    // Calculate total marks for each student
    for (auto& student : bioStudents) {
        calculateTotalMarks(student);
    }
    for (auto& student : mathStudents) {
        calculateTotalMarks(student);
    }

    // Sort students based on total marks
    sort(bioStudents.begin(), bioStudents.end(), compareStudents);
    sort(mathStudents.begin(), mathStudents.end(), compareStudents);

    // Assign ranks
    for (size_t i = 0; i < bioStudents.size(); ++i) {
        bioStudents[i].rank = i + 1;
    }
    for (size_t i = 0; i < mathStudents.size(); ++i) {
        mathStudents[i].rank = i + 1;
    }

    // Output ranks to console and file
    ofstream outFile("rankings.txt");
    if (outFile.is_open()) {
        outFile << "Bioscience Stream Ranks:\n";
        for (const auto& student : bioStudents) {
            cout << student.name << " - School Rank: " << student.rank << " - Class Rank: " << student.rank % studentsPerClass << endl;
            outFile << student.name << " - School Rank: " << student.rank << " - Class Rank: " << student.rank % studentsPerClass << endl;
        }

        outFile << "\nMath Stream Ranks:\n";
        for (const auto& student : mathStudents) {
            cout << student.name << " - School Rank: " << student.rank << " - Class Rank: " << student.rank % studentsPerClass << endl;
            outFile << student.name << " - School Rank: " << student.rank << " - Class Rank: " << student.rank % studentsPerClass << endl;
        }

        outFile.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }

    return 0;
}
