#include<iostream>
using namespace std;

class Student{
  private:
    int rollno;
    string name;
    int marks;
  public:
    void initStudent(){
       rollno = 1;
       name = "Aditi";
       marks = 23;

    }
    void acceptStudentFromConsole(){
        cout << "Enter Student Rollno :";
        cin >> rollno;
        cout << "Name of Student :";
        cin >> name;
        cout << "Student's Marks :";
        cin >> marks;

    }
    void printStudentOnConsole(){
        cout <<"Rollno :"<<rollno<<"\nName :"<<name<<"\nMarks :"<<marks<<endl;
    }
};

int main(){
    int choice;
    Student s;
    s.initStudent();

    do{
        cout << "0.Exit" << endl;
        cout << "1.acceptStudent" <<endl;
        cout << "2.printStudent" <<endl;
        cout << "Enter choice :" <<endl;
        cin >> choice;
        
        switch(choice)
        {
          case 0:
             cout << "Exit" << endl;
             break;
          case 1:
             s.acceptStudentFromConsole();
             break;
          case 2:
             s.printStudentOnConsole();
             break;
          default :
             cout <<  "Wrong Choice....."<< endl;
             break;
        }     
    }while (choice != 0);

    return 0;
}