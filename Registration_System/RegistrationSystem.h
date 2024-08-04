#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H
#include <iostream>
#include <string>
using namespace std;


class Courses
{
public:
    int courseId;
    string courseName;

};

class Student
{
public:
    Courses *copy;
    int studentId;
    string firstName;
    string lastName;
    Courses *kurs;
    int kurscnt;
};

class RegistrationSystem
{
public:
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent( const int studentId, const string firstName, const string lastName );
    void deleteStudent( const int studentId );
    void addCourse( const int studentId, const int courseId, const string courseName );
    void withdrawCourse( const int studentId, const int courseId );
    void cancelCourse( const int courseId );
    void showStudent( const int studentId );
    void showCourse( const int courseId );
    void showAllStudents();

private:
    Student *std;
    Student *copy;
    int counter;
};


#endif // REGISTRATIONSYSTEM_H
