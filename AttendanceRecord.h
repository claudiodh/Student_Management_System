//
// Created by Claudio Delgado on 2024-11-11.
//

// AttendanceRecord.h
#ifndef ATTENDANCERECORD_H
#define ATTENDANCERECORD_H

#include <string>
#include <memory>

enum class AttendanceStatus { Present, Absent };

class Student; // Forward declaration

class AttendanceRecord {
public:
    AttendanceRecord(const std::shared_ptr<Student>& student, const std::string& courseCode, const std::string& date, AttendanceStatus status);

    std::string getDate() const;
    AttendanceStatus getStatus() const;
    std::shared_ptr<Student> getStudent() const;
    std::string getCourseCode() const;

    bool operator<(const AttendanceRecord& other) const;

private:
    std::shared_ptr<Student> student;
    std::string courseCode;
    std::string date;
    AttendanceStatus status;
};

#endif // ATTENDANCERECORD_H