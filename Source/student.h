#ifndef STUDENT_H
#define STUDENT_H
#include "globalTypes.h"
#include <set>
#include <string>

class Student
{
public:
    Student(std::string lastName,std::string firstName,Level ownLevel ,Skill requestedSkill, std::set<Language> languages);
    long getId() const;
    std::string getLastName() const;
    std::string getFirstName() const;

    Level getOwnLevel() const;

    Skill getRequestedSkill() const;

private:
    static long maxId;
    long id;
    std::string lastName, firstName;
    Level ownLevel = Level::BEGINNER;
    std::set<Language> languages;//wie vector aber alles ist drinne ungeordnet
    Skill requestedSkill = Skill::SKI;
};
#endif // STUDENT_H
