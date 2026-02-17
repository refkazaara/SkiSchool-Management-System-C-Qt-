#include "course.h"
Course::Course(Level level, Skill type, Teacher *teacher):
    level(level),type(type),teacher(teacher)
{

}
//-------------------------------AUFGABE 2------------------------------------//
void Course::clearStudents()
{
    this->students.clear();
}

void Course::addStudent(Student *s)
{
    // Überprüfe zur Sicherheit, ob der Zeiger nicht null ist
        if (s != nullptr) {
            students.push_back(s);
        }
}
Teacher *Course::getTeacher() const
{
    return teacher;
}
std::vector<Student *> Course::getStudents() const
{
    return students;
}

Level Course::getLevel() const
{
    return level;
}

Skill Course::getType() const
{
    return type;
}

unsigned int Course::getGroupSize() const
{
    return groupSize;
}
