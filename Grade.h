//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef GRADE_H
#define GRADE_H

#include "GradeComponent.h"
#include "GradeType.h"
#include <memory>

// Forward Declarations
class Student;
class Course;
class GradeCalculationStrategy;

class Grade : public GradeComponent {
private:
    std::shared_ptr<Student> student;
    std::shared_ptr<Course> course;
    GradeType type;
    double totalGrade;
    std::shared_ptr<GradeCalculationStrategy> calculationStrategy;

public:
    Grade(const std::shared_ptr<Student>& student,
          const std::shared_ptr<Course>& course,
          const std::string& name,
          double score,
          GradeType type,
          const std::shared_ptr<GradeCalculationStrategy>& strategy);

    // Getter and setter for score
    void setScore(double score);
    double getScore() const;

    // Method to calculate total grade using the strategy
    void calculateTotalGrade();

    // Getter and setter for type
    GradeType getType() const;
    void setType(GradeType type);

    // Getter and setter for calculationStrategy
    std::shared_ptr<GradeCalculationStrategy> getCalculationStrategy() const;
    void setCalculationStrategy(const std::shared_ptr<GradeCalculationStrategy>& strategy);

    // Getter for totalGrade
    double getTotalGrade() const;

    // Getter for course and student
    std::shared_ptr<Course> getCourse() const;
    std::shared_ptr<Student> getStudent() const;
};

#endif // GRADE_H


