//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef GRADECOMPONENT_H
#define GRADECOMPONENT_H

#include <string>

class GradeComponent {
protected:
    std::string name;
    double score;

public:
    GradeComponent(const std::string& name, double score);

    // Getter and setter for name
    std::string getName() const;
    void setName(const std::string& name);

    virtual // Getter and setter for score
    double getScore() const;

    virtual void setScore(double score);
};

#endif // GRADECOMPONENT_H
