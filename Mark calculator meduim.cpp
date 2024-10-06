#include <iostream>
#include <string>

using namespace std;

int main() {
    int numCourses, numStudents;

    cout << " Enter number of courses: ";
    cin >>  numCourses;
    cout<<"\n";
    cout<<"\n";
    cout << " Enter number of students: ";
    cin >>  numStudents;
    cout<<"\n";
    cout<<"\n";
    string studentNames[100];
    int totalMarks[100] = {0};  

    for (int course = 1; course <= numCourses; ++course) {
        string courseName;
        cout << " \nEnter the name of course " << course << ": ";
        cin.ignore();
        getline(cin, courseName);
        cout<<"\n";

        if (course == 1) {
            for (int i = 0; i < numStudents; ++i) {
                cout << " Enter the name of student " << i + 1 << ": ";
                getline(cin, studentNames[i]);
            }
        }

        for (int i = 0; i < numStudents; ++i) {
            int marks;
            
            cout << " Enter the marks for " << studentNames[i] << " in course " << course << ": ";
            cin >>  marks;
            totalMarks[i] += marks;  
        }
    }

    int highestMarks = totalMarks[0];
    string topStudent = studentNames[0];
    for (int i = 1; i < numStudents; ++i) {
        if (totalMarks[i] > highestMarks) {
            highestMarks = totalMarks[i];
            topStudent = studentNames[i];
        }
    }
     cout<<"\n";
     cout<<"\n";
    cout << " \nTotal marks for each student:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << ": " << totalMarks[i] << " marks\n";
    }
    cout<<"\n";
    cout<<"\n";
    cout << " \nThe student with the highest total marks is " << topStudent 
         << "  with " << highestMarks << "  marks.\n";
          cout<<"\n";
          cout<<"  *********** Covertion done ************\n";
    return 0;
}

