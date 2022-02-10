//Code was created while following along a LinkedIn Learning course. I did not write 100% of the code by myself

#include "StuRec.h"
#include <iostream>
#include <fstream>

//within class Student 
Student::Student(int iid, std::string iname)
{
    id = iid;
    name = iname;
}
int Student::get_id()
{
    return id;
}
std::string Student::get_name()
{
    return name;
}
void Student::set_id(int newid)
{
    id = newid;
}
void Student::set_name(std::string newname)
{
    name = newname;
}

//within class Course
Course::Course(int iid, std::string iname, int icredits)
{
    id = iid;
    name = iname;
    credits = icredits;
}
int Course::get_id()
{
    return id;
}
std::string Course::get_name()
{
    return name;
}
int Course::get_credits()
{
    return credits;
}
void Course::set_id(int newid)
{
    id = newid;
}
void Course::set_name(std::string newname)
{
    name = newname;
}
void Course::set_credits(int newcredits)
{
    credits = newcredits;
}

//within class Grade
Grade::Grade(int istudent_id, int icourse_id, char igrade)
{
    student_id = istudent_id;
    course_id = icourse_id;
    grade = igrade;
}
int Grade::get_student_id()
{
    return student_id;
}
int Grade::get_course_id()
{
    return course_id;
}
char Grade::get_grade()
{
    return grade;
}
void Grade::set_student_id(int newsid)
{
    student_id = newsid;
}
void Grade::set_course_id(int newcid)
{
    course_id = newcid;
}
void Grade::set_grade(char newgrade)
{
    grade = newgrade;
}

//within class StudentRecords

float StudentRecords::get_num_grade(char letter)
{
    float numgrd = 0;
    switch (letter)
    {
    case 'A': numgrd = 4.0;
        break;
    case 'B': numgrd = 3.0;
        break;
    case 'C': numgrd = 2.0;
        break;
    case 'D': numgrd = 1.0;
        break;
    };
    return numgrd;
}

void StudentRecords::add_student(int sid, std::string name)
{
    students.push_back(Student(sid, name));
}

void StudentRecords::add_course(int cid, std::string name, unsigned char credits)
{
    courses.push_back(Course(cid, name, credits));
}

void StudentRecords::add_grade(int student_id, int course_id, char grade)
{
    grades.push_back(Grade(student_id, course_id, grade));
}

std::string StudentRecords::get_student_name(int sid)
{
    int i = 0;
    while (i < students.size() && students[i].get_id() != sid)
    {
        i++;
    }
    return students[i].get_name();
}

unsigned char StudentRecords::get_course_credits(int cid)
{
    int i = 0;
    while (i < courses.size() && courses[i].get_id() != cid)
    {
        i++;
    }
    return courses[i].get_credits();
}

float StudentRecords::get_GPA(int sid)
{
    float gpa = 0.0;
    int totalcred = 0;

    //loop thru grades to find student of that id
    for (Grade& grd : grades)
    {
        if (grd.get_student_id() == sid)
        {
            auto coursecred = StudentRecords::get_course_credits(grd.get_course_id());
            gpa += coursecred * StudentRecords::get_num_grade(grd.get_grade());
            totalcred += coursecred;
        }
    }
    gpa = gpa / totalcred;
    return gpa;

}
std::string StudentRecords::get_course_name(int cid)
{
    int j = 0;
    while (j < courses.size() && courses[j].get_id() != cid)
    {
        j++;
    }
    return courses[j].get_name();

}

void StudentRecords::report_card(int sid, std::ostream& stream)
{
    std::string studentname = StudentRecords::get_student_name(sid);
    stream << "Report Card for " << studentname << std::endl;
    for (Grade& grd : grades)
    {
        if (grd.get_student_id() == sid)
        {
            stream << StudentRecords::get_course_name(grd.get_course_id()) << " : " << grd.get_grade() << std::endl;
        }
    }
    stream << "GPA: " << StudentRecords::get_GPA(sid) << std::endl;

}
