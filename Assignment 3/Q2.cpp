#include<iostream>
using namespace std;
class Time
{
private:
    int hrs;
    int min;
    int sec;
public:
    Time()
    {
        hrs = 10;
        min = 10;
        sec = 10;
    
    }
    Time(int hrs,int min,int sec)
    {
       this->hrs = hrs;
       this->min = min;
       this->sec = sec;
    }
    int getHour()
    {
        return hrs;
    } 
    int getMinute()
    {
        return min;
    }
    int getSecond()
    {
        return sec;
    }
    void printTime()
    {
        cout<<"Time ="<<hrs<<":"<<min<<":"<<sec<<endl;
    }
    void setHour(int hrs)
    {
        this->hrs=hrs;
    }
    void setMinute(int min)
    {
        this->min=min;
    }
    void setSecond(int sec)
    {
        this->sec=sec;
    }
    
};

int main()
{
    int h, m, s;
    cout << "Enter hrs:" <<endl;
    cin >> h;
    cout << "Enter mins:" <<endl;
    cin >> m;
    cout << "Enter secs:" <<endl;
    cin >> s;
    Time *ptr1;
    ptr1 = new Time;
    ptr1->printTime();

    Time *ptr2 = new Time(h, m, s);
    ptr2->printTime();
    
    ptr2->setHour(h);
    ptr2->setMinute(m);
    ptr2->setSecond(s);
    cout<<"Time = "<<ptr2->getHour()<<":"<<ptr2->getMinute()<<":"<<ptr2->getSecond()<<":"<<endl;
   
    delete ptr1;
    delete ptr2;
    
    ptr1= NULL;
    ptr2= NULL;

    return 0;

}