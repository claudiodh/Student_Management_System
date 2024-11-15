//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef SIMPLEGRADECALCULATIONSTRATEGY_H
#define SIMPLEGRADECALCULATIONSTRATEGY_H

#include "GradeCalculationStrategy.h"

class SimpleGradeCalculationStrategy : public GradeCalculationStrategy {
public:
    double calculateGrade(double score) override;
};

#endif // SIMPLEGRADECALCULATIONSTRATEGY_H

