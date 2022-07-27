#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <ctime>
using namespace std;
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};
void inputFunc(); // Function
void assignGrade();
studentType studentArr[20];
int count = 0;
void outputFunc();
void sorting();
void addRecord(string, string, int);
main()
{
    system("cls");
    inputFunc();
    assignGrade();
    sorting();
    outputFunc();
}
void inputFunc()
{
    bool flag = true;
    int x = 1;
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
    int *p;
    *p = x;
    while (x == 1)
    {
        flag = true;
        cout << "Enter First Name :- " << endl;
        cin >> studentFName;
        cout << "Enter Last Name :- " << endl;
        cin >> studentLName;
        while (flag)
        {
            cout << "Enter Test Score :- " << endl;
            cin >> testScore;
            if (testScore < 0 || testScore > 100)
            {
                cout << "Inavlid Test Score" << endl;
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        addRecord(studentFName, studentLName, testScore);
        cout << "Press 1 to enter another record" << endl;
        cin >> x;
    }
}
void addRecord(string fName, string lName, int score)
{

    studentArr[count].studentFName = fName;
    studentArr[count].studentLName = lName;
    studentArr[count].testScore = score;
    count++;
}
void assignGrade()
{
    for (int i = 0; i < count; i++)
    {
        if (studentArr[i].testScore >= 90)
        {
            studentArr[i].grade = 'A';
        }
        else if (studentArr[i].testScore >= 80 && studentArr[i].testScore < 90)
        {
            studentArr[i].grade = 'B';
        }
        else if (studentArr[i].testScore >= 70 && studentArr[i].testScore < 80)
        {
            studentArr[i].grade = 'C';
        }
        else if (studentArr[i].testScore >= 60 && studentArr[i].testScore < 70)
        {
            studentArr[i].grade = 'D';
        }
        else if (studentArr[i].testScore < 40)
        {
            studentArr[i].grade = 'F';
        }
    }
}
void sorting()
{
    int tempT;
    string tempN;
    char tempG;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (studentArr[j].testScore > studentArr[i].testScore)
            { // TestScore
                tempT = studentArr[i].testScore;
                studentArr[i].testScore = studentArr[j].testScore;
                studentArr[j].testScore = tempT;
                // Grade
                tempG = studentArr[i].grade;
                studentArr[i].grade = studentArr[j].grade;
                studentArr[j].grade = tempG;
                // Last Name
                tempN = studentArr[i].studentLName;
                studentArr[i].studentLName = studentArr[j].studentLName;
                studentArr[j].studentLName = tempN;
                // First Name
                tempN = studentArr[i].studentFName;
                studentArr[i].studentFName = studentArr[j].studentFName;
                studentArr[j].studentFName = tempN;
            }
        }
    }
}
void outputFunc()
{
    system("cls");
    for (int i = 0; i < count; i++)
    {
        cout << studentArr[i].studentLName << ", " << studentArr[i].studentFName << " " << studentArr[i].testScore << " " << studentArr[i].grade << endl;
    }
}