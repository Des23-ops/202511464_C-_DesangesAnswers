#include "Student.h"

int main()
{
    // Creating student.txt only once

    ifstream checkFile("student.txt");

    if(!checkFile)
    {
        ofstream file("student.txt");

        file << "202312051,lithacynthia,18" << endl;
        file << "202312052,dessama,18" << endl;
        file << "202312053,david,20" << endl;

        file.close();
    }

    checkFile.close();

    int choice;

    do
    {
        cout <<"\t\t===STUDENT MANAGEMENT SYSTEM====" << endl;
        
        

        cout <<"\t\t1. Display All Students" << endl;
        cout <<"\t\t2. Search Student" << endl;
        cout <<"\t\t3. Update Student" << endl;
        cout <<"\t\t4. Delete Student" << endl;
        cout <<"\t\t5. Exit" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice){
	
            case 1:
                displayStudents();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
               cout << "\033[31m Exit of the program.\033[0m" << endl;
                break;

            default:
                cout << "Wrong choice! Please try again" << endl;
        }

    } while(choice != 5);

    return 0;
}
