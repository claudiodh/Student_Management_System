//
// Created by Claudio Delgado on 2024-11-11.
#ifndef DATAREPOSITORY_H
#define DATAREPOSITORY_H

#include <memory>
#include <vector>
#include <string>
#include "Student.h"
#include "Course.h"

class DataRepository {
public:
    static DataRepository& getInstance() {
        static DataRepository instance;
        return instance;
    }

    void addStudent(const std::shared_ptr<Student>& student);
    void addCourse(const std::shared_ptr<Course>& course);

    std::shared_ptr<Student> getStudentByRollNumber(const std::string& rollNumber);
    std::shared_ptr<Course> getCourseByCode(const std::string& code);

    void saveStudentData(const std::shared_ptr<Student>& student);
    void saveCourseData(const std::shared_ptr<Course>& course);

private:
    DataRepository() = default;
    std::vector<std::shared_ptr<Student>> students;
    std::vector<std::shared_ptr<Course>> courses;
};

#endif // DATAREPOSITORY_H