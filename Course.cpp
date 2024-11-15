//
// Created by Claudio Delgado on 2024-11-11.
//
#include "Course.h"
#include "AttendanceRecord.h"
#include "Student.h"
#include "Grade.h"
#include <iostream>
#include <memory>

Course::Course(const std::string& name, const std::string& code)
        : name(name), code(code) {
    saveCourseData();
}

void Course::enrollStudent(const std::shared_ptr<Student>& student) {
    std::weak_ptr<Student> studentWeakPtr = student; // Convert shared_ptr to weak_ptr
    enrolledStudents.insert(studentWeakPtr); // Store the weak_ptr
    student->saveStudentData();
}

void Course::addAttendanceRecord(const AttendanceRecord& record) {
    attendanceRecords.push_back(record);
}

void Course::markAttendance(const std::shared_ptr<Student>& student,
                            const std::string& date, AttendanceStatus status) {
    AttendanceRecord record(student, code, date, status);
    addAttendanceRecord(record);
}

void Course::viewAttendance() const {
    for (const auto& record : attendanceRecords) {
        std::cout << "Student Roll: " << record.getStudent()->getRollNumber()
                  << ", Date: " << record.getDate()
                  << ", Status: " << (record.getStatus() == AttendanceStatus::Present ? "Present" : "Absent") << "\n";
    }
}

void Course::printInfo() const {
    std::cout << "Course Name: " << name << "\nCourse Code: " << code << std::endl;
}

std::string Course::getName() const {
    return name;
}

std::string Course::getCode() const {
    return code;
}

void Course::assignGrade(const std::string& studentRoll,
                         const std::shared_ptr<Grade>& grade) {
    grades.push_back(grade);

    // Find the student and add the grade
    for (const auto& studentWeakPtr : enrolledStudents) {
        if (auto studentSharedPtr = studentWeakPtr.lock()) { // Correctly use lock() on weak_ptr
            if (studentSharedPtr->getRollNumber() == studentRoll) {
                studentSharedPtr->addGrade(grade); // Access private method
                break;
            }
        }
    }
}

void Course::saveCourseData() {
    DataRepository::getInstance().saveCourseData(shared_from_this());
}


