//
// Created by Claudio Delgado on 2024-11-11.
//
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <memory>
#include <set>
#include <vector>
#include "Course.h"
#include "AttendanceRecord.h"
#include "Grade.h"
#include "DataRepository.h"

class Course;

class Student : public std::enable_shared_from_this<Student> {
public:
    Student(const std::string& name,
            const std::string& rollNumber,
            int age,
            const std::string& contactInfo);

    void enrollInCourse(const std::shared_ptr<Course>& course);
    void viewAttendance(const std::string& courseCode) const;
    void viewGrades(const std::string& courseCode) const;
    void printInfo() const;

    std::string getName() const;
    void setName(const std::string& name);

    std::string getRollNumber() const;
    void setRollNumber(const std::string& rollNumber);

    int getAge() const;
    void setAge(int age);

    std::string getContactInfo() const;
    void setContactInfo(const std::string& contactInfo);

    std::string getRoll() const;

    bool operator<(const Student& other) const {
        return rollNumber < other.rollNumber;
    }

    void saveStudentData();

private:
    friend class Course;

    void addGrade(const std::shared_ptr<Grade>& grade);

    std::string name;
    std::string rollNumber;
    int age;
    std::string contactInfo;
    std::set<std::shared_ptr<Course>> enrolledCourses;
    std::set<AttendanceRecord> attendanceRecords;
    std::vector<std::shared_ptr<Grade>> grades;
};

#endif // STUDENT_H