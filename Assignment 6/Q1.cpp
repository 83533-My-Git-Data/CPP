#include<iostream>
using namespace std;
/*Q1. Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type Date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.
Employee class should be inherited from Person.
Implement following classes. Test all functionalities in main().
(Note - Perform the Association and Inheritance in the above case.)*/

class Date{
    int day;
    int month;
    int year;
public:
    Date(){
        day = 1;
        month = 1;
        year = 1990;
    }
    void acceptDate(){
        cout << "Enter day :"<<endl;
        cin >> day;
        cout << "Enter month :"<< endl;
        cin >> month;
        cout << "Enter Year :"<<endl;
        cin >> year;
    }
    void displayDate(){
        cout << "Date :" <<day <<"/"<<month<<"/"<<year<<endl;
    }
};

class Person{
    string name;
    string address;
    Date Dob;
public:
    Person(){
        name = "";
        address = "";
    }

    virtual void acceptData(){
        cout << "Enter Name :"<<endl;
        cin >> name;
        cout << "Enter Address :"<< endl;
        cin >> address;
        cout << "Enter Date of birth:"<<endl;
        Dob.acceptDate();
    }

    virtual void displayData(){
        cout << "Name :"<<name <<endl;
        cout << "Address :"<<address <<endl;
        cout << "Date of Birth :" << endl;
        Dob.displayDate();
    }
};

class Employee:public Person
{
    int empid;
    string dept;
    double salary;
    Date doj;

public :
    void acceptDate(){
        doj.acceptDate();
    }
    void displayDate(){
        doj.displayDate();
    }
    void acceptData(){
        cout << "Enter Emp id:"<< endl;
        cin >>empid;
        cout << "Enter department :"<<endl;
        cin >> dept;
        cout << "Enter salary :"<<endl;
        cin >> salary;
        Person :: acceptData();
    }

    void displayData(){
        cout << "Empid :"<< empid << endl;
        cout << "Department :"<< dept << endl;
        cout << "Salary :"<< salary << endl;
        Person :: displayData();
    }
};

int main(){
    Date d;
    Person p;
    Employee e;
    Person *ptr = new Employee();
    ptr->acceptData();
    ptr->displayData();

    delete ptr;
    ptr = NULL;
    return 0;
} 
