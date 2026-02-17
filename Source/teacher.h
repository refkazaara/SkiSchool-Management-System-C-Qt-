#ifndef TEACHER_H
#define TEACHER_H

#include "globalTypes.h"
#include <string>
#include <set>
class Teacher
{
public:
    Teacher(std::string lastName, std::string firstName, Seniority seniority,std::set<Language> languages,Skill mySkill);
    long getId() const;
    std::string getLastName() const;
    std::string getFirstName() const;
    Seniority getSeniority() const;
    Skill getMySkill() const;
    std::set<Language> getLanguages() const;
private:
    long id;
    std::string lastName, firstName;
    Seniority seniority = Seniority::GRADUATE;
    Skill mySkill = Skill::SKI;
    std::set<Language> languages;
    static long maxId;
};

#endif // TEACHER_H
