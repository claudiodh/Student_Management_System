//
// Created by Claudio Delgado on 2024-11-11.
//
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "Student.h"
#include "Grade.h"
#include "AttendanceRecord.h"
#include "DataRepository.h"

class Course : public std::enable_shared_from_this<Course> {
public:
    Course(const std::string& name, const std::string& code);

    void enrollStudent(const std::shared_ptr<Student>& student);
    void addAttendanceRecord(const AttendanceRecord& record);
    void markAttendance(const std::shared_ptr<Student>& student, const std::string& date, AttendanceStatus status);
    void viewAttendance() const;
    void printInfo() const;
    std::string getName() const;
    std::string getCode() const;
    void assignGrade(const std::string& studentRoll, const std::shared_ptr<Grade>& grade);

    bool operator<(const Course& other) const {
        return code < other.code;
    }

private:
    std::string name;
    std::string code;
    std::vector<AttendanceRecord> attendanceRecords;
    std::vector<std::shared_ptr<Grade>> grades;
    std::set<std::weak_ptr<Student>, std::owner_less<std::weak_ptr<Student>>> enrolledStudents;

    void saveCourseData();
};

#endif // COURSE_H