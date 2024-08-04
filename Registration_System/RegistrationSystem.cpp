#include "RegistrationSystem.h"
#include <iostream>
#include <string>
using namespace std;

RegistrationSystem::RegistrationSystem()
{
    counter = 0;
}

RegistrationSystem::~RegistrationSystem()
{
    for(int i=0; i<counter; i++)
    {
        delete [] std[i].kurs;
    }
    delete [] std;
}
void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName )
{
    for (int i = 0; i < counter; i++)
    {
        if(std[i].studentId == studentId)
        {
            cout<<"Student "<<studentId<<" already exists"<<endl;
            return;
        }

    }
    if(firstName == "")
    {
        cout<<"The first name cannot be empty"<<endl;
        return;
    }
    else if(lastName == "")
    {
        cout<<"The last name cannot be empty"<<endl;
        return;
    }
    else if(studentId < 0)
    {
        cout<<"The input student id "<<studentId<<" is < 0, so it cannot be added "<<endl;
        return;
    }
    else
    {
        counter++;
		std = new Student[counter];
	
        for(int i=0; i<counter-1; i++)
        {
            std[i].studentId = copy[i].studentId;
            std[i].firstName = copy[i].firstName;
            std[i].lastName = copy[i].lastName;
            std[i].kurscnt = copy[i].kurscnt;
            std[i].kurs = copy[i].kurs;
            std[i].copy = copy[i].copy;
        }
    
        std[counter-1].kurscnt = 0;
        std[counter-1].studentId = studentId;
        std[counter-1].firstName = firstName;
        std[counter-1].lastName = lastName;
        std[counter-1].kurs = NULL;
        
        if(counter>1) {
            delete [] copy;
		}
        this->copy = this->std;
        

        cout<<"Student "<<studentId<<" has been added"<<endl;

       int temp;
        string temps;
        Courses *sad;

        for(int i = 0; i < counter; i++)
        {
    
            for(int j = 0; j < counter; j++)
            {
                if(std[i].studentId < std[j].studentId)
                {
                    temp = std[i].studentId;
                    std[i].studentId = std[j].studentId;
                    std[j].studentId = temp;
                    temps = std[i].firstName;
                    std[i].firstName = std[j].firstName;
                    std[j].firstName = temps;
                    temps = std[i].lastName;
                    std[i].lastName = std[j].lastName;
                    std[j].lastName = temps;
                    sad = std[i].kurs;
                    std[i].kurs = std[j].kurs;
                    std[j].kurs = sad;
                    sad = std[i].copy;
                    std[i].copy = std[j].copy;
                    std[j].copy = sad;
                    temp = std[i].kurscnt;
                    std[i].kurscnt = std[j].kurscnt;
                    std[j].kurscnt = temp;
                    
                }	
            }
        }
    }


}
void RegistrationSystem::deleteStudent( const int studentId )
{
    int temp=-1;
    string temps;
    int tempi;
    Courses *sad;
    for(int i=0; i<counter; i++)
    {
        if(std[i].studentId == studentId)
        {
            temp=i;
            break;
        }
    }
    if(temp==-1) {
    	cout<<"Student "<<studentId<< " does not exist"<<endl;
    	return;
	}
    for(int i=temp; i<counter-1; i++)
    {
        tempi=std[i].studentId;
        std[i].studentId = std[i+1].studentId;
        std[i+1].studentId = tempi;
        tempi=std[i].kurscnt;
        std[i].kurscnt = std[i+1].kurscnt;
        std[i+1].kurscnt = tempi;
        temps=std[i].firstName;
        std[i].firstName = std[i+1].firstName;
        std[i+1].firstName = temps;
        temps=std[i].lastName;
        std[i].lastName = std[i+1].lastName;
        std[i+1].lastName = temps;
        sad = std[i].kurs;
        std[i].kurs = std[i+1].kurs;
        std[i+1].kurs = sad;
        sad = std[i].copy;
        std[i].copy = std[i+1].copy;
        std[i+1].copy = sad;

    }
    counter--;

    std = new Student[counter];

    for(int i=0; i<counter; i++)
    {
        std[i].studentId = copy[i].studentId;
        std[i].firstName = copy[i].firstName;
        std[i].lastName = copy[i].lastName;
        std[i].kurscnt = copy[i].kurscnt;
        std[i].kurs = copy[i].kurs;
        std[i].copy = copy[i].copy;
    }
    if(counter>1)
        delete [] copy;
    this->copy = this->std;

    cout<<studentId<<" has been deleted"<<endl;

}
void RegistrationSystem::showAllStudents()
{
    if(counter == 0)
    {
        cout<<"There are no students in the system"<<endl;
        return;
    }
    cout<<endl;
    cout<<"Student id "<<"First name "<<"Last name "<<endl;
    int const size = 11;
    for (int i = 0; i < counter; i++)
    {
        if(std[i].studentId != 0)
        {
            int a = std[i].firstName.length();
            cout<<std[i].studentId<<"       "<< std[i].firstName;
            for(int j = 0; j < size - a; j++)
            {
                cout<<" ";
            }
            cout<< std[i].lastName<<"\t"<<endl;

            if(std[i].kurscnt != 0 && std[i].kurs != NULL)
            {
                cout<<"        "<<"Course id  "<<"Course name"<<endl;
                for(int j=0; j<std[i].kurscnt; j++)
                {
                    cout<<"        "<<std[i].kurs[j].courseId<<"        "<<std[i].kurs[j].courseName<<endl;
                }
            }
        }

    }
}

void RegistrationSystem::showStudent( const int studentId )
{
    for (int i = 0; i < counter; i++)
    {
        if(std[i].studentId == studentId )
        {
            cout<<"Student id "<<"First name "<< "Last name"<<endl;
            cout<<std[i].studentId<<"       "<<std[i].firstName;

            int const size = 11;
            int a = std[i].firstName.length();
            for(int j = 0; j < size - a; j++)
            {
                cout<<" ";
            }
            cout<<std[i].lastName<<endl;

            if(std[i].kurscnt != 0)
            {
                cout<<"        "<<"Course id  "<<"Course name"<<endl;
                for(int j=0; j<std[i].kurscnt; j++)
                {
                    cout<<"        "<<std[i].kurs[j].courseId<<"        "<<std[i].kurs[j].courseName<<endl;
                }
            }
            return;
        }
    }
    cout<<endl;
    cout<<"Student " << studentId<< " does not exists"<<endl;
}
void RegistrationSystem::addCourse( const int studentId, const int courseId, const string courseName )
{
    int temp=-1;
    for(int i=0; i<counter; i++)
    {
        if(std[i].studentId == studentId)
        {
            temp=i;
            break;
        }
    }
    if(temp==-1)
    {
        cout<<"Student "<<studentId<<" that you want to add a course does not exist"<<endl;
        return;
    }
    for(int j=0; j<std[temp].kurscnt; j++)
    {
        if(std[temp].kurs[j].courseId == courseId)
        {
            cout<<"Student "<<studentId<<" is already enrolled in course "<<courseId<<endl;
            return;
        }
    }

    std[temp].kurscnt++;
    std[temp].kurs = new Courses[std[temp].kurscnt];

    for(int i=0; i<std[temp].kurscnt-1; i++)
    {
        std[temp].kurs[i].courseId = std[temp].copy[i].courseId;
        std[temp].kurs[i].courseName = std[temp].copy[i].courseName;
    }
    std[temp].kurs[std[temp].kurscnt-1].courseId = courseId;
    std[temp].kurs[std[temp].kurscnt-1].courseName = courseName;
    if(std[temp].kurscnt>1)
        delete [] std[temp].copy;
    std[temp].copy = std[temp].kurs;
    cout<<"Course "<<courseId<<" has been added to student "<< studentId<<endl;
}

void RegistrationSystem::withdrawCourse( const int studentId, const int courseId )
{
    int temp=-1;
    int tempc=-1;
    int tempId;
    string tempName;
    for(int i=0; i<counter; i++)
    {
        if(std[i].studentId == studentId)
        {
            temp=i;
            break;
        }
    }
    if(temp==-1)
    {
        cout<<"Student "<<studentId<<" does not exists"<<endl;
        return;
    }
    for(int i=0; i<std[temp].kurscnt; i++)
    {
        if(std[temp].kurs[i].courseId == courseId)
        {
            tempc=i;
            break;
        }
    }
    if(tempc==-1)
    {
        cout<<"course is not avaliable for the student"<<endl;
        return;
    }

    for(int i=tempc; i<std[temp].kurscnt-1; i++)
    {
        tempId = std[temp].kurs[i].courseId;
        std[temp].kurs[i].courseId = std[temp].kurs[i+1].courseId;
        std[temp].kurs[i+1].courseId = tempId;
        tempName = std[temp].kurs[i].courseName;
        std[temp].kurs[i].courseName = std[temp].kurs[i+1].courseName;
        std[temp].kurs[i+1].courseName = tempName;
    }

    std[temp].kurscnt--;
    std[temp].kurs = new Courses[std[temp].kurscnt];

    for(int i=0; i<std[temp].kurscnt; i++)
    {
        std[temp].kurs[i].courseId = std[temp].copy[i].courseId;
        std[temp].kurs[i].courseName = std[temp].copy[i].courseName;
    }

    if(std[temp].kurscnt!=0)
        delete [] std[temp].copy;
    std[temp].copy = std[temp].kurs;
    for(int i=0; i<std[temp].kurscnt; i++)
    {
        std[temp].copy[i].courseId = std[temp].kurs[i].courseId;
        std[temp].copy[i].courseName = std[temp].kurs[i].courseName;
    }

    cout<<"Student "<<studentId<<" has been withdrawn from course "<<courseId<<endl;
}

void RegistrationSystem::cancelCourse( const int courseId )
{	
	bool course_active = false;
    int tempId;
    string tempName;
    for(int temp=0; temp<counter; temp++)
    {
        for(int j=0; j<std[temp].kurscnt; j++)
        {
            if(std[temp].kurs[j].courseId == courseId)
            {
				course_active = true;
                for(int i=j; i<std[temp].kurscnt-1; i++)
                {
                    tempId = std[temp].kurs[i].courseId;
                    std[temp].kurs[i].courseId = std[temp].kurs[i+1].courseId;
                    std[temp].kurs[i+1].courseId = tempId;
                    tempName = std[temp].kurs[i].courseName;
                    std[temp].kurs[i].courseName = std[temp].kurs[i+1].courseName;
                    std[temp].kurs[i+1].courseName = tempName;
                }

                std[temp].kurscnt--;
                std[temp].kurs = new Courses[std[temp].kurscnt];

                for(int k=0; k<std[temp].kurscnt; k++)
                {

                    std[temp].kurs[k].courseId = std[temp].copy[k].courseId;
                    std[temp].kurs[k].courseName = std[temp].copy[k].courseName;
                }

                if(std[temp].kurscnt!=0)
                    delete [] std[temp].copy;
                std[temp].copy = std[temp].kurs;
                
                
            }
        }
    }
    if (course_active == true)
		cout<<"Course "<<courseId<< " has been canceled"<<endl;
    else
		cout<<"Course "<<courseId<< " does not exists"<<endl;
}

void RegistrationSystem::showCourse(const int courseId)
{
    bool error=false;
    for(int i=0; i<counter; i++)
    {
        for(int j=0; j<std[i].kurscnt; j++)
        {

            if(std[i].kurs[j].courseId == courseId)
            {
                if(error==false)
                {
                    cout<<"Course id   "<<"Course Name"<<endl;
                    cout<<std[i].kurs[j].courseId<<"     "<<std[i].kurs[j].courseName<<endl;
                    cout<<"        "<<"Student id "<<"First name "<<"Last name"<<endl;
                }
                cout<<"        "<< std[i].studentId<<"       "<<std[i].firstName;

                int const size = 11;
                int a = std[i].firstName.length();
                for(int j = 0; j < size - a; j++)
                {
                    cout<<" ";
                }
                cout<<std[i].lastName<<endl;
                error=true;
            }
        }
    }
    if(error==false)
    {
        cout<<"Course "<<courseId<<" does not exists"<<endl;
        return;
    }
}






