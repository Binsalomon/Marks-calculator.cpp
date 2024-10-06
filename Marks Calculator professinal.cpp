#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findTopStudent(const vector<string>& studentNames, const vector<int>& totalMarks) {
    int topIndex = 0;
    for (int i = 1; i < totalMarks.size(); ++i) {
        if (totalMarks[i] > totalMarks[topIndex]) {
            topIndex = i;
        }
    }
    return topIndex;
}

int main() {
    int numCourses, numStudents;
    
    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of students to calculate their marks: ";
    cin >> numStudents;

    vector<string> studentNames(numStudents);
    vector<int> totalMarks(numStudents, 0);

    for (int course = 1; course <= numCourses; ++course) {
        string courseName;
        cout << "Enter the name of course " << course << ": ";
        cin.ignore();  
        getline(cin, courseName);

        if (course == 1) {
            for (int i = 0; i < numStudents; ++i) {
                cout << "Enter the name of student " << i + 1 << ": ";
                getline(cin, studentNames[i]);
            }
        }

        for (int i = 0; i < numStudents; ++i) {
            int marks;
            cout << "Enter the marks of " << studentNames[i] << " for course " << course << ": ";
            cin >> marks;
            totalMarks[i] += marks;
        }
    }

    int topStudentIndex = findTopStudent(studentNames, totalMarks);
    
    cout << "\nResults:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << " has a total of " << totalMarks[i] << " marks.\n";
    }
    cout << "\nThe student with the highest total marks is: " << studentNames[topStudentIndex]
         << " with " << totalMarks[topStudentIndex] << " marks.\n";

    return 0;
}

