#include<iostream>
using namespace std;
class Date{
private:
    int day;
    int month;
    int year; 
public:
    void initDate (){
        day = 1;
        month=1;
        year = 1970;    
    }
    void acceptDateFromConsole(){
        cout <<"Enter day, month and year :";
        cin >> day >> month >> year;
    }
    void printDateOnConsole(){
        cout << "Date:" << day << ":" << month << ":" << year<< endl;
    }
    bool isLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0))
            return true;
        else
            return false;
    }
};

int main(){
    class Date d;
    int choice;
    d.initDate();
    do{
        cout<<"1. Accept date"<<endl;
        cout<<"2. Print Date"<<endl;
        cout<<"3. Leap year"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your Choice:"<<endl;
        cin >> choice;

        switch(choice){
            case 1: 
                d.acceptDateFromConsole();
                break;
            case 2:
                d.printDateOnConsole();
                break;
            case 3:
                if(d.isLeapYear())
                    cout << "leap Year"<< endl;
                else
                   cout << "Not a leap year"<< endl;
                break;
            case 4:
                cout<<"Exit"<<endl;
                break;
            default:
                cout <<"wrong choice"<<endl;        
        }
    }while(choice!=4);
    return 0;
 }