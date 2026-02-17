#ifndef SKISCHOOL_H
#define SKISCHOOL_H
#include "course.h"
#include <iostream>
#include "teacher.h"
#include "student.h"
#include <map>
#include <set>
#include<fstream>
#include<sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include<QString>
using namespace std;

class SkiSchool
{
public:
    SkiSchool();

    void userDialog();
    std::vector<Student *> getStudents() const;
    void readStudentFile(std::string filename);
    void createCourse();
    void distributeStudents();
    QString showAllCourses(); // Rückgabetyp ändern!
    QString getRawStudentList();

private:
    std::map<long,Course*> courses{};
    std::vector<Teacher*> teachers{new Teacher(std::string("Neureuther"), std::string("Felix"), Seniority::SENIOR,std::set<Language>{Language::GERMAN, Language::ENGLISH}, Skill::SKI),
                new Teacher(std::string("Goggia"), std::string("Sofia"), Seniority::SENIOR,std::set<Language>{Language::ITALIAN, Language::ENGLISH}, Skill::SKI),
                new Teacher(std::string("Deerksen"), std::string("Geertje"), Seniority::GRADUATE,std::set<Language>{Language::DUTCH, Language::ENGLISH}, Skill::SNOWBOARD),
                new Teacher(std::string("Odermatt"), std::string("Marco"), Seniority::GRADUATE,std::set<Language>{Language::GERMAN, Language::ENGLISH, Language::FRENCH}, Skill::BOTH),
                new Teacher(std::string("Shiffrin"), std::string("Mikaela"), Seniority::SENIOR,std::set<Language>{Language::ENGLISH}, Skill::BOTH),
                new Teacher(std::string("Strasser"), std::string("Linus"), Seniority::GRADUATE,std::set<Language>{Language::GERMAN, Language::ENGLISH}, Skill::SKI)};
    std::vector<Student*> students{};
    std::vector<Student*> waitingList;
};
#endif // SKISCHOOL_H
