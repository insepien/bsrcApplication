#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "StuRec.h" 

using namespace std;


void initialize_txt_gpa();


StudentRecords SR; // to use: initalize and run 

ifstream inFile;  
ofstream outFile;  
string str;
string studentname;
int studentid;

int main()
{
    //read the data from files into classes 
    initialize_txt_gpa();

    //write new record into report file
    outFile.open("C:\\Users\\Mya\\OneDrive\\Documents\\linkedinlearn\\report.txt", fstream::app);
    SR.report_card(3, outFile);
    outFile << "======================================" << endl;
    outFile << endl;
    outFile.close();


    return 0;
};

void initialize_txt_gpa()
{
    //read student file
    inFile.open("C:\\Users\\Mya\\OneDrive\\Documents\\linkedinlearn\\students.txt");

    while (!inFile.eof()) 
    {
        // get student id and name
        getline(inFile, str);
        studentid = stoi(str);
        getline(inFile, str);
        studentname = str;

        //add to class StudentRecords
        SR.add_student(studentid, studentname);
    }
    inFile.close();

    //read course file
    inFile.open("C:\\Users\\Mya\\OneDrive\\Documents\\linkedinlearn\\courses.txt");
    int cid;
    unsigned char cred;
    string cname;

    while (!inFile.eof()) 
    {
        //read course info
        getline(inFile, str);
        cid = stoi(str);
        getline(inFile, str);
        cname = str;
        getline(inFile, str);
        cred = str[0];
        // add course info to StudentRecords
        SR.add_course(cid, cname, cred);
       
    }
    inFile.close();

    //read grades file
    inFile.open("C:\\Users\\Mya\\OneDrive\\Documents\\linkedinlearn\\grades.txt");
    int sid;
    int ccid;
    char grade;

    while (!inFile.eof()) 
    {
        //read grades 
        getline(inFile, str);
        sid = stoi(str);
        getline(inFile, str);
        ccid = stoi(str);
        getline(inFile, str);
        grade = str[0];
        //add grades to StudentRecords
        SR.add_grade(sid, ccid, grade);
    }
    inFile.close();
}



