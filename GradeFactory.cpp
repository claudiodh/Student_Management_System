//
// Created by Claudio Delgado on 2024-11-11.
//

#include "GradeFactory.h"

std::shared_ptr<Grade> GradeFactory::createGrade(const std::shared_ptr<Student>& student,
                                                 const std::shared_ptr<Course>& course,
                                                 GradeType type,
                                                 const std::string& name,
                                                 double score,
                                                 const std::shared_ptr<GradeCalculationStrategy>& strategy) {
    return std::make_shared<Grade>(student, course, name, score, type, strategy);
}



