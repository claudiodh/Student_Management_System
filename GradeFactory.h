//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef GRADEFACTORY_H
#define GRADEFACTORY_H

#include "GradeComponent.h"
#include "GradeType.h"
#include "Grade.h"
#include <string>
#include <memory>

class GradeFactory {
public:
    static std::shared_ptr<Grade> createGrade(const std::shared_ptr<Student>& student,
                                              const std::shared_ptr<Course>& course,
                                              GradeType type,
                                              const std::string& name,
                                              double score,
                                              const std::shared_ptr<GradeCalculationStrategy>& strategy);
};

#endif // GRADEFACTORY_H



