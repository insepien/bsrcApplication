//Code was created while following along a LinkedIn Learning course. I did not write 100% of the code by myself

#pragma once

#include <string>
#include <vector>

class Student
{
private:
    int id;
    std::string name;
public:
    Student(int iid, std::string iname);
    int get_id();
    std::string get_name();
    void set_id(int newid);
    void set_name(std::string newname);
};

class Course
{
private:
    int id;
    std::string name;
    int credits;
public:
    Course(int iid, std::string iname, int icredits);
    int get_id();
    std::string get_name();
    int get_credits();
    void set_id(int newid);
    void set_name(std::string newname);
    void set_credits(int newcredits);
};

class Grade
{
private:
    int student_id;
    int course_id;
    char grade;
public:
    Grade(int istudent_id, int icourse_id, char igrade);
    int get_student_id();
    int get_course_id();
    char get_grade();
    void set_student_id(int newsid);
    void set_course_id(int newcid);
    void set_grade(char newgrade);
};

class StudentRecords
{
private:
    std::vector<Student> students;
    std::vector<Course> courses;
    std::vector<Grade> grades;

    float get_num_grade(char);

public:
    void add_student(int, std::string);
    void add_course(int, std::string, unsigned char);
    void add_grade(int, int, char);

    std::string get_student_name(int);
    unsigned char get_course_credits(int);
    float get_GPA(int);
    std::string get_course_name(int);
    void report_card(int id, std::ostream&);
};


#pragma once
