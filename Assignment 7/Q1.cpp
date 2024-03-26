/*Q1. Provide menu driven code for the functionalities:
1. Accept Employee
2. Display the count of all employees with respect to designation
3. Display All Managers
4. Display All Salesman
5. Display All SalesManagers*/

#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{
    int choice;
    int index = 0;
    int Cmanagers = 0;
    int Csalesman = 0;
    int CsalesManger = 0;
    Employee *arr[10];

    do{
        cout<<"0.Exit"<<endl;
        cout<<"1.Accept Employee"<<endl;
        cout<<"2.Display count of Employees with respect to designation:"<<endl;
        cout<<"3.Display all managers:"<<endl;
        cout<<"4.Display all salesman:"<<endl;
        cout<<"5.Display all SalesManager:"<<endl;
        cout<<"Enter choice:"<<endl;
        cin>>choice;

        switch(choice){
            case 0:
                cout<<"Thank you"<<endl;
                break;
            case 1:
                int ch;
                do{
                    cout<<"0.Exit"<<endl;
                    cout<<"1.Count of Manager:"<<endl;
                    cout<<"2.Count of Salesman:"<<endl;
                    cout<<"3.Count of Sales Manager:"<<endl;
                    cout<<"Enter ch:"<<endl;
                    cin >> ch;
                    
                    switch(ch){
                        case 0: 
                            cout<<"Exit"<<endl;
                            break;
                        case 1:
                            cout<<"___Accept Manager___"<<endl;
                            if(index<10){
                                arr[index]= new Manager();
                                arr[index]->accept();
                                index++;
                                Cmanagers++;
                            }
                            else{
                                cout<<"Array is full...."<<endl;
                            }
                            cout<<"*********************"<<endl;
                            break;
                        case 2:
                            cout<<"___Accept Salesman___"<<endl;
                            if(index<10){
                                arr[index]= new Salesman();
                                arr[index]->accept();
                                index++;
                                Csalesman++;
                            }
                            else{
                                cout<<"Array is full...."<<endl;
                            }
                            cout<<"*********************"<<endl;
                            break;
                        case 3:
                            cout<<"___Accept Sales manager___"<<endl;
                            if(index<10){
                                arr[index]= new SalesManager();
                                arr[index]->accept();
                                index++;
                                CsalesManger++;
                            }
                            else{
                                cout<<"Array is full...."<<endl;
                            }
                            cout<<"*********************"<<endl;
                            break;
                        default:
                            cout<<" Wrong choice"<<endl;
                            break;
                        }
                   }while(ch!=0);
                 break;
            case 2:  
                cout << "Display Count of Employees based on designation:"<<endl;  
                for(int i = 0; i < index; i++){
                    arr[i]->display();
                }
                cout<<"**************************"<<endl;

                cout << "Count of Employee:"<< index << endl;
                cout << "Count of Managers:"<< Cmanagers << endl;
                cout << "Count of Salesman:"<< Csalesman << endl;
                cout << "Count of Sales Managers:" << CsalesManger<<endl;
                break;
                
            case 3:
                cout << "Display all Managers:"<<endl;
                for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Manager)){
                    arr[i]->display();
                    cout<<"**********************"<<endl;
                }
                break;
            case 4:
                cout << "Display all Salesman";
                for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Salesman)){
                    arr[i]->display();
                    cout<<"**********************"<<endl;
                }
                break;
            case 5:
                cout<<"Display all Sales Manager:"<<endl;
                for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(SalesManager)){
                    arr[i]->display();
                    cout<<"**********************"<<endl;
                }
                break;
            default:
               cout<< "Wrong choice"<<endl;
               break; 
           }

        
    } while (choice!=0); 
      for (int i = 0; i < index; i++)
          delete arr[i];
    return 0;
}