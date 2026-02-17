#include "teacher.h"
long Teacher::maxId=0;  // Jetzt bekommt der erste Lehrer die ID 0

Teacher::Teacher(std::string lastName, std::string  firstName, Seniority seniority, std::set<Language> languages, Skill mySkill):
    lastName(lastName),firstName(firstName),seniority(seniority),mySkill(mySkill),languages(languages)
{
    id=maxId++;
}

long Teacher::getId() const
{return id;}
std::string  Teacher::getLastName() const
{return lastName;}
std::string  Teacher::getFirstName() const
{return firstName;}
Seniority Teacher::getSeniority() const
{return seniority;}
Skill Teacher::getMySkill() const
{ return mySkill;}
std::set<Language> Teacher::getLanguages() const
{ return languages;}
