//
// Created by Claudio Delgado on 2024-11-11.
//

#include "AttendanceRecord.h"
#include "Student.h"

AttendanceRecord::AttendanceRecord(const std::shared_ptr<Student>& student, const std::string& courseCode, const std::string& date, AttendanceStatus status)
    : student(student), courseCode(courseCode), date(date), status(status) {}

std::string AttendanceRecord::getDate() const {
    return date;
}

AttendanceStatus AttendanceRecord::getStatus() const {
    return status;
}

std::shared_ptr<Student> AttendanceRecord::getStudent() const {
    return student;
}

std::string AttendanceRecord::getCourseCode() const {
    return courseCode;
}

bool AttendanceRecord::operator<(const AttendanceRecord& other) const {
    return date < other.date;
}
