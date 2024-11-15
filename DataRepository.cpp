//
// Created by Claudio Delgado on 2024-11-11.
//
#include "DataRepository.h"

void DataRepository::addStudent(const std::shared_ptr<Student>& student) {
    students.push_back(student);
}

void DataRepository::addCourse(const std::shared_ptr<Course>& course) {
    courses.push_back(course);
}

std::shared_ptr<Student> DataRepository::getStudentByRollNumber(const std::string& rollNumber) {
    for (const auto& student : students) {
        if (student->getRollNumber() == rollNumber) {
            return student;
        }
    }
    return nullptr;
}

std::shared_ptr<Course> DataRepository::getCourseByCode(const std::string& code) {
    for (const auto& course : courses) {
        if (course->getCode() == code) {
            return course;
        }
    }
    return nullptr;
}

void DataRepository::saveStudentData(const std::shared_ptr<Student>& student) {
    // Implementation for saving student data
}

void DataRepository::saveCourseData(const std::shared_ptr<Course>& course) {
    // Implementation for saving course data
}