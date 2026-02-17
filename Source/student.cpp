#include "student.h"

long Student::maxId=1;

Student::Student(std::string lastName, std::string firstName, Level ownLevel, Skill requestedSkill, std::set<Language> languages):
    lastName(lastName),firstName(firstName),ownLevel(ownLevel),requestedSkill(requestedSkill),languages(languages)
{id=maxId++;
}

long Student::getId() const
{return id;}
std::string Student::getLastName() const
{return lastName;}
std::string Student::getFirstName() const
{ return firstName;}

Level Student::getOwnLevel() const
{
    return ownLevel;
}

Skill Student::getRequestedSkill() const
{
    return requestedSkill;
}
