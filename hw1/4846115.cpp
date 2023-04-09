#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class Student{
    private:
        string name;
        int grade;
    public:
        Student();
        ~Student();
        void set_grade(int);
        int get_grade();
        string get_name();
        void set_name(string);
};

Student::Student()
{
}

Student::~Student()
{
}

void Student::set_grade(int sgrade)
{
    if(sgrade<0)
        grade=0;
    else
        grade = sgrade;
}

int Student::get_grade()
{
    return grade;
}

string Student::get_name()
{
    return name;
}

void Student::set_name(string sname)
{
    name = sname;
}



bool perform_operation(char);
void print_menu();
void listStudents();
void addStudent();
void maxGradeStudent();


int capacity = 0;
Student astudents[10];

int main(){

    bool end = false;
    char choice;


    while (!end)
    {
        print_menu();
        cin >> choice;
        end = perform_operation(choice);
    }

    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "Choose an operation" << endl;
    cout << "A: Add student" << endl;
    cout << "L: List students" << endl;
    cout << "M: Name and grade of the student with the highest grade" << endl;
    cout << "E: Exit" << endl;
    cout << "Enter a choice {A,L,M,E}: ";
}

bool perform_operation(char choice)
{
    bool terminate = false;
    string strday;

    switch (choice)
    {
    case 'L':
    case 'l':
        listStudents();
        break;
    case 'A':
    case 'a':
        addStudent();
        break;
    case 'M':
    case 'm':
        maxGradeStudent();
        break;
    case 'E':
    case 'e':
        terminate = true;
        break;
    default:
        cout << "Error: You have entered an invalid choice" << endl;
        cin >> choice;
        terminate = perform_operation(choice);
        break;
    }
    return terminate;
}

void listStudents()
{   
    int grade;

    string name;
    
    for(int i=0;i<capacity;i++){
        grade=astudents[i].get_grade();
        name=astudents[i].get_name();
        cout <<name<<grade<<endl;

}

}

void addStudent()
{
    string name;
    int grade;
    cout << "Enter the name of student: ";
    cin >> name;
    cout << "Enter the grade of student: ";
    cin >> grade;

    //*** Fill here. Set the name and grade of the student for astudents array
    //and increase capacity by 1.

    astudents[capacity].set_name(name);
    astudents[capacity].set_grade(grade);
    capacity++;
    
}

void maxGradeStudent()
{
    string mname;
    int mgrade=0;
    for(int i=0;capacity>i;i++){
        string cname=astudents[i].get_name();
        int cgrade=astudents[i].get_grade();
            if(cgrade>mgrade){
                mgrade=cgrade;
                mname=cname;
        }
    }    
    cout <<mname<<" "<<mgrade;
}