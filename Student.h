#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Student
{
private:
    string rollNumber;
    string studentName;
    string studentAge;

public:
    Student();
    Student(string roll, string name, string age);

    string getRoll();
    string getName();
    string getAge();

    void display();
};

void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif
