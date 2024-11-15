//
// Created by Claudio Delgado on 2024-11-11.
//

#include "GradeComponent.h"

GradeComponent::GradeComponent(const std::string& name, double score)
        : name(name), score(score) {}

std::string GradeComponent::getName() const {
    return name;
}

void GradeComponent::setName(const std::string& name) {
    this->name = name;
}

double GradeComponent::getScore() const {
    return score;
}

void GradeComponent::setScore(double score) {
    this->score = score;
}


