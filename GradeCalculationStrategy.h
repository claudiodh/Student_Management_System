//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef GRADECALCULATIONSTRATEGY_H
#define GRADECALCULATIONSTRATEGY_H

class GradeCalculationStrategy {
public:
    virtual ~GradeCalculationStrategy() = default;
    virtual double calculateGrade(double score) = 0;
};

#endif // GRADECALCULATIONSTRATEGY_H

