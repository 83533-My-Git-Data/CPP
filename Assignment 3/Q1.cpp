#include<iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;
    static const double PI;

public:
    Cylinder(): Cylinder(4.1, 3.1)
    {
        // radius=4.1;
        // height=3.1;
    }
    Cylinder(double radius,double height){
        this->radius=radius;
        this->height=height;
    }
    double getRadius()
    {
        return radius;
    }
    void setRadius(double radius)
    {
        this->radius =radius;
    }
    double getHeight()
    {
        return height;
    }
    void setHeight(double height)
    {
        this->height =height;
    }

    double getVolume()
    {
        return PI* radius * radius * height;
    }
    void printVolume()
    {
        cout<<"Print Volume :" << getVolume()<<endl;
    }

};
 
const double Cylinder::PI=3.14;

int main()
{
    double r;
    double h;
    cout << "Enter Radius"<< endl;
    cin >> r;
    cout << "Enter height"<< endl;
    cin >> h;
    
    Cylinder c1;
    c1.printVolume();
    Cylinder c3;
    c3.setRadius(r);
    cout<<"getRadius "<<c3.getRadius()<<endl;

    c3.setHeight(h);
    cout<<"getHeight "<<c3.getHeight()<<endl;

    Cylinder c2(r, h);
    c2.printVolume();
    
    
   return 0;
}