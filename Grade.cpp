//
// Created by Claudio Delgado on 2024-11-11.
//

#include "Grade.h"
#include "Student.h"
#include "Course.h"
#include "GradeCalculationStrategy.h"

Grade::Grade(const std::shared_ptr<Student>& student,
             const std::shared_ptr<Course>& course,
             const std::string& name,
             double score,
             GradeType type,
             const std::shared_ptr<GradeCalculationStrategy>& strategy)
        : GradeComponent(name, score), student(student), course(course), type(type),
          calculationStrategy(strategy), totalGrade(0.0) {}

void Grade::setScore(double score) {
    this->score = score;
}

double Grade::getScore() const {
    return score;
}

void Grade::calculateTotalGrade() {
    if (calculationStrategy) {
        totalGrade = calculationStrategy->calculateGrade(score);
    } else {
        totalGrade = score;
    }
}

GradeType Grade::getType() const {
    return type;
}

void Grade::setType(GradeType type) {
    this->type = type;
}

std::shared_ptr<GradeCalculationStrategy> Grade::getCalculationStrategy() const {
    return calculationStrategy;
}

void Grade::setCalculationStrategy(const std::shared_ptr<GradeCalculationStrategy>& strategy) {
    calculationStrategy = strategy;
}

double Grade::getTotalGrade() const {
    return totalGrade;
}

std::shared_ptr<Course> Grade::getCourse() const {
    return course;
}

std::shared_ptr<Student> Grade::getStudent() const {
    return student;
}


