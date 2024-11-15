//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H

#include <string>

class StudentManagementSystem {
public:
    void run(); // Starts the application loop

private:
    void displayMenu();
    void handleUserChoice(int choice);

    // Existing methods
    void registerStudent();
    void addCourse();
    void enrollStudentInCourse();
    void viewStudentRecords();
    void markAttendance();
    void viewAttendanceRecords();

    // Grade-related methods
    void assignGrades();
    void viewStudentGrades();
};

#endif // STUDENTMANAGEMENTSYSTEM_H
