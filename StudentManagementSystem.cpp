//
// Created by Claudio Delgado on 2024-11-11.
//

// StudentManagementSystem.cpp

#include "StudentManagementSystem.h"
#include "DataRepository.h"
#include "Student.h"
#include "Course.h"
#include "Grade.h"
#include "GradeType.h"
#include "GradeFactory.h"
#include "GradeCalculationStrategy.h"
#include "SimpleGradeCalculationStrategy.h"
#include <iostream>
#include <string>
#include <memory>

void StudentManagementSystem::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline character from the input buffer
        handleUserChoice(choice);
    } while (choice != 9); // Assuming 9 is the option to exit
}

void StudentManagementSystem::displayMenu() {
    std::cout << "Student Management System\n";
    std::cout << "1. Register Student\n";
    std::cout << "2. Add Course\n";
    std::cout << "3. Enroll Student in Course\n";
    std::cout << "4. View Student Records\n";
    std::cout << "5. Mark Attendance\n";
    std::cout << "6. View Attendance Records\n";
    std::cout << "7. Assign Grades\n";
    std::cout << "8. View Student Grades\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter choice: ";
}

void StudentManagementSystem::handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            registerStudent();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            enrollStudentInCourse();
            break;
        case 4:
            viewStudentRecords();
            break;
        case 5:
            markAttendance();
            break;
        case 6:
            viewAttendanceRecords();
            break;
        case 7:
            assignGrades();
            break;
        case 8:
            viewStudentGrades();
            break;
        case 9:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
    std::cout << std::endl;
}

void StudentManagementSystem::registerStudent() {
    std::string name, rollNumber, contactInfo;
    int age;

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter roll number: ";
    std::getline(std::cin, rollNumber);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cin.ignore(); // Clear the newline character
    std::cout << "Enter contact info: ";
    std::getline(std::cin, contactInfo);

    auto student = std::make_shared<Student>(name, rollNumber, age, contactInfo);
    DataRepository::getInstance().addStudent(student);

    std::cout << "Student registered successfully.\n";
}

void StudentManagementSystem::addCourse() {
    std::string name, code;

    std::cout << "Enter course name: ";
    std::getline(std::cin, name);
    std::cout << "Enter course code: ";
    std::getline(std::cin, code);

    auto course = std::make_shared<Course>(name, code);
    DataRepository::getInstance().addCourse(course);

    std::cout << "Course added successfully.\n";
}

void StudentManagementSystem::enrollStudentInCourse() {
    std::string rollNumber, courseCode;

    std::cout << "Enter student roll number: ";
    std::getline(std::cin, rollNumber);
    std::cout << "Enter course code: ";
    std::getline(std::cin, courseCode);

    auto& repository = DataRepository::getInstance();
    auto student = repository.getStudentByRollNumber(rollNumber);
    auto course = repository.getCourseByCode(courseCode);

    if (student && course) {
        course->enrollStudent(student);
        student->enrollInCourse(course);
        std::cout << "Student enrolled in course successfully.\n";
    } else {
        std::cout << "Invalid student roll number or course code.\n";
    }
}

void StudentManagementSystem::viewStudentRecords() {
    std::string rollNumber;
    std::cout << "Enter student roll number: ";
    std::getline(std::cin, rollNumber);

    auto student = DataRepository::getInstance().getStudentByRollNumber(rollNumber);

    if (student) {
        student->printInfo();
    } else {
        std::cout << "Student not found.\n";
    }
}

void StudentManagementSystem::markAttendance() {
    std::string rollNumber, courseCode, date;
    int statusInt;

    std::cout << "Enter student roll number: ";
    std::getline(std::cin, rollNumber);
    std::cout << "Enter course code: ";
    std::getline(std::cin, courseCode);
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Enter attendance status (1 for Present, 0 for Absent): ";
    std::cin >> statusInt;
    std::cin.ignore(); // Clear the newline character

    AttendanceStatus status = (statusInt == 1) ? AttendanceStatus::Present : AttendanceStatus::Absent;

    auto& repository = DataRepository::getInstance();
    auto student = repository.getStudentByRollNumber(rollNumber);
    auto course = repository.getCourseByCode(courseCode);

    if (student && course) {
        course->markAttendance(student, date, status);
        std::cout << "Attendance recorded successfully.\n";
    } else {
        std::cout << "Invalid student roll number or course code.\n";
    }
}

void StudentManagementSystem::viewAttendanceRecords() {
    std::string rollNumber, courseCode;
    std::cout << "Enter student roll number: ";
    std::getline(std::cin, rollNumber);
    std::cout << "Enter course code: ";
    std::getline(std::cin, courseCode);

    auto student = DataRepository::getInstance().getStudentByRollNumber(rollNumber);

    if (student) {
        student->viewAttendance(courseCode); // Pass the courseCode argument
    } else {
        std::cout << "Student not found.\n";
    }
}

void StudentManagementSystem::assignGrades() {
    std::string studentRoll, courseCode, gradeName;
    int gradeTypeInt;
    double score;

    std::cout << "Enter student roll number: ";
    std::getline(std::cin, studentRoll);
    std::cout << "Enter course code: ";
    std::getline(std::cin, courseCode);
    std::cout << "Enter grade name: ";
    std::getline(std::cin, gradeName);
    std::cout << "Enter grade type (1: Assignment, 2: Quiz, 3: Exam): ";
    std::cin >> gradeTypeInt;
    std::cout << "Enter score: ";
    std::cin >> score;
    std::cin.ignore(); // Clear the newline character

    GradeType gradeType;
    switch (gradeTypeInt) {
        case 1:
            gradeType = GradeType::Assignment;
            break;
        case 2:
            gradeType = GradeType::Quiz;
            break;
        case 3:
            gradeType = GradeType::Exam;
            break;
        default:
            std::cout << "Invalid grade type.\n";
            return;
    }

    auto& repository = DataRepository::getInstance();
    auto student = repository.getStudentByRollNumber(studentRoll);
    auto course = repository.getCourseByCode(courseCode);

    if (student && course) {
        // Create a simple calculation strategy
        auto strategy = std::make_shared<SimpleGradeCalculationStrategy>();

        // Create the grade using the factory
        auto grade = GradeFactory::createGrade(student, course, gradeType, gradeName, score, strategy);

        // Calculate the total grade
        grade->calculateTotalGrade();

        // Assign the grade to the course and student
        course->assignGrade(studentRoll, grade);

        std::cout << "Grade assigned successfully.\n";
    } else {
        std::cout << "Invalid student roll number or course code.\n";
    }
}

void StudentManagementSystem::viewStudentGrades() {
    std::string studentRoll, courseCode;
    std::cout << "Enter student roll number: ";
    std::getline(std::cin, studentRoll);
    std::cout << "Enter course code: ";
    std::getline(std::cin, courseCode);

    auto student = DataRepository::getInstance().getStudentByRollNumber(studentRoll);

    if (student) {
        student->viewGrades(courseCode); // This method was updated in Student.cpp
    } else {
        std::cout << "Student not found.\n";
    }
}


