#ifndef COURSE_H
#define COURSE_H
#include "globalTypes.h"
#include "teacher.h"
#include "student.h"
#include <vector>
class Course
{
public:
    Course(Level level ,Skill type, Teacher* teacher);
    Teacher *getTeacher() const;
    void clearStudents();
    void addStudent(Student* s);
    std::vector<Student *> getStudents() const;
    Level getLevel() const;
    Skill getType() const;
    unsigned int getGroupSize() const;

private:

    Level level = Level::BEGINNER;
    Teacher* teacher = nullptr;
    std::vector<Student*> students;
    const unsigned int groupSize = 8;
    Skill type = Skill::SKI;
};

#endif // COURSE_H
