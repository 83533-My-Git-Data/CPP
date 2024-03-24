/*Q1. Implement following classes. Test all functionalities in main().
Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of
type date.
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should
be of type date.*/

#include<iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public :
    Date(){
        day = 12;
        month = 07;
        year = 2001;
    }
    void acceptDate(){
        cout << "Enter day :"<<endl;
        cin >> day;
        cout << "Enter month:"<<endl;
        cin >> month;
        cout << "Enter year"<<endl;
        cin >> year;
    }
    void displayDate(){
        cout<<"Date :"<<day <<"/"<<month<<"/"<<year<<endl;
    }
};
class Person {
private:
    string name;
    string address;
    Date Dob;
public:
    Person(){
        name ="";
        address = "";
    }
    void acceptDetails(){
        cout << "Enter name:" <<endl;
        cin >> name;
        cout << "Enter address:"<< endl;
        cin >> address;
        cout << "Enter date of birth:" << endl;
        Dob.acceptDate();
    }
    void displayDetails(){
        cout << "Name:" <<name <<endl;
        cout << "Address:"<< address <<endl;
        cout << "Date of Birth:"<<endl;
        Dob.displayDate();
    }

};
class Employee {
private:
    int id;
    double sal;
    string dept;
    Date joining_date;
public: 
    Employee(){
        id = 1;
        sal = 2000;
        dept ="";
    }
    void acceptEmployeeDetails(){
        cout << "Enter id:"<< endl;
        cin >>id;
        cout <<"Enter salary:" << endl;
        cin >> sal;
        cout << "Enter department:"<< endl;
        cin >> dept;
        joining_date.acceptDate();
    }
    void displayEmployeeDetails(){
        cout << "Id :"<< id <<endl;
        cout << "Salary :"<<sal <<endl;
        cout << "Department:"<<dept<<endl;
        cout << "Employee Details:"<<endl;
        joining_date.displayDate();
    }
};
int main(){
    Employee e;
    Person p;
    e.acceptEmployeeDetails();
    e.displayEmployeeDetails();
    p.acceptDetails();
    p.displayDetails();

    return 0;

}
