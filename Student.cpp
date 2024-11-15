//
// Created by Claudio Delgado on 2024-11-11.
//

#include "Student.h"
#include <iostream>

Student::Student(const std::string& name,
                 const std::string& rollNumber,
                 int age,
                 const std::string& contactInfo)
        : name(name), rollNumber(rollNumber), age(age), contactInfo(contactInfo) {
    saveStudentData();
}

void Student::enrollInCourse(const std::shared_ptr<Course>& course) {
    enrolledCourses.insert(course);
}

void Student::viewAttendance(const std::string& courseCode) const {
    for (const auto& record : attendanceRecords) {
        if (record.getCourseCode() == courseCode) {
            std::cout << "Date: " << record.getDate() << ", Status: " << (record.getStatus() == AttendanceStatus::Present ? "Present" : "Absent") << "\n";
        }
    }
}

void Student::viewGrades(const std::string& courseCode) const {
    for (const auto& grade : grades) {
        if (grade->getCourse()->getCode() == courseCode) {
            // Optionally, display more information about the grade
            std::cout << "Grade Name: " << grade->getName()
                      << ", Score: " << grade->getScore()
                      << ", Total Grade: " << grade->getTotalGrade() << "\n";
        }
    }
}

void Student::printInfo() const {
    std::cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nAge: " << age << "\nContact Info: " << contactInfo << std::endl;
}

std::string Student::getName() const {
    return name;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

std::string Student::getRollNumber() const {
    return rollNumber;
}

void Student::setRollNumber(const std::string& rollNumber) {
    this->rollNumber = rollNumber;
}

int Student::getAge() const {
    return age;
}

void Student::setAge(int age) {
    this->age = age;
}

std::string Student::getContactInfo() const {
    return contactInfo;
}

void Student::setContactInfo(const std::string& contactInfo) {
    this->contactInfo = contactInfo;
}

std::string Student::getRoll() const {
    return rollNumber;
}

void Student::addGrade(const std::shared_ptr<Grade>& grade) {
    grades.push_back(grade);
}

void Student::saveStudentData() {
    DataRepository::getInstance().saveStudentData(shared_from_this());
}

