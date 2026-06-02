#include "Student.h"

Student::Student()
{
}

Student::Student(string roll, string name, string age)
{
    rollNumber = roll;
    studentName = name;
    studentAge = age;
}

string Student::getRoll()
{
    return rollNumber;
}

string Student::getName()
{
    return studentName;
}

string Student::getAge()
{
    return studentAge;
}

void Student::display()
{
    cout << rollNumber << ","
         << studentName << ","
         << studentAge << endl;
}

void displayStudents()
{
    ifstream file("student.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void searchStudent()
{
    string roll;
    string line;

    cout << "Enter Roll Number: ";
    cin >> roll;

    ifstream file("student.txt");

    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id;

        getline(ss, id, ',');

        if(id == roll)
        {
            cout << "\nStudent Found:" << endl;
            cout << line << endl;

            found = true;
        }
    }

    if(found == false)
    {
        cout << "Student not found." << endl;
    }

    file.close();
}

void updateStudent()
{
    string roll;
    string line;

    cout << "Enter Roll Number to Update: ";
    cin >> roll;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id;
        string name;
        string age;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        if(id == roll)
        {
            found = true;

            string newRoll;
            string newName;
            string newAge;

            cout << "Enter New Roll Number: ";
            cin >> newRoll;

            cout << "Enter New Name: ";
            cin >> newName;

            cout << "Enter New Age: ";
            cin >> newAge;

            temp << newRoll << ","
                 << newName << ","
                 << newAge << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    if(found)
    {
        remove("student.txt");
        rename("temp.txt", "student.txt");

        cout << "Student Updated Successfully." << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "Student Not Found." << endl;
    }
}

void deleteStudent()
{
    string roll;
    string line;

    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    ifstream file("student.txt");
    ofstream temp("temp.txt");

    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string id;

        getline(ss, id, ',');

        if(id == roll)
        {
            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    if(found)
    {
        remove("student.txt");
        rename("temp.txt", "student.txt");

        cout << "Student Deleted Successfully." << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "Student Not Found." << endl;
    }
}
