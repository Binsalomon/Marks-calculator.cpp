#include <iostream>  // Includes the input and output library
#include <string>    // Includes the string library to handle text

using namespace std; // Allows us to use standard commands like 'cout' and 'cin' easily

int main() {
    int numCourses, numStudents;

    // Step 1: Ask how many courses there are
    cout << "Enter number of courses: ";
    cin >> numCourses;  // Take input from the user and store in 'numCourses'

    // Step 2: Ask how many students there are
    cout << "Enter number of students: ";
    cin >> numStudents;  // Take input from the user and store in 'numStudents'

    // Arrays to store names of students and their total marks
    string studentNames[100]; // Can store up to 100 student names
    int totalMarks[100] = {0}; // Array to store total marks for each student, all set to 0

    // Step 3: Loop to handle each course
    for (int course = 1; course <= numCourses; ++course) {
        string courseName; // This will store the name of the course

        // Ask for the course name
        cout << "\nEnter the name of course " << course << ": ";
        cin.ignore();         // To handle the newline character after previous input
        getline(cin, courseName); // Get the course name from the user

        // Step 4: Ask for student names only the first time (course 1)
        if (course == 1) {
            for (int i = 0; i < numStudents; ++i) {
                cout << "Enter the name of student " << i + 1 << ": ";
                getline(cin, studentNames[i]); // Store the student names
            }
        }

        // Step 5: Ask for each student's marks for the current course
        for (int i = 0; i < numStudents; ++i) {
            int marks; // Variable to store marks
            cout << "Enter the marks for " << studentNames[i] << " in course " << course << ": ";
            cin >> marks; // Take the marks input from the user
            totalMarks[i] += marks; // Add the marks to the student's total marks
        }
    }

    // Step 6: Find the student with the highest total marks
    int highestMarks = totalMarks[0]; // Assume the first student has the highest marks
    string topStudent = studentNames[0]; // Assume the first student is the top student

    // Go through all students to find who has the highest total marks
    for (int i = 1; i < numStudents; ++i) {
        if (totalMarks[i] > highestMarks) {
            highestMarks = totalMarks[i]; // Update the highest marks
            topStudent = studentNames[i]; // Update the top student
        }
    }

    // Step 7: Show total marks for each student
    cout << "\nTotal marks for each student:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << ": " << totalMarks[i] << " marks\n"; // Show student name and their total marks
    }

    // Show the student with the highest marks
    cout << "\nThe student with the highest total marks is " << topStudent 
         << " with " << highestMarks << " marks.\n";

    return 0; // End the program
}

