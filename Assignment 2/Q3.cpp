#include<iostream>
using namespace std;

class Address{
 private:
    string building;
    string street; 
    string city;
    int pin;

public:
   Address()
    {
        building = "Raghunath Residency";
        street = "workshop road"; 
        city = "Nanded";
        pin = 431605;
    }

    Address(string building, string street,string city, int pin)
    {
       this->building = building;
       this->street = street;
       this->city = city;
       this->pin = pin;
    }
    
    void setBuilding(string building){
        this->building = building;
    }

    void setStreet(string street){
        this->street = street;
    }

    void setCity(string city){
        this->city = city;
    }

    void setPin(int pin){
        this->pin = pin;
    }

    string getBuilding(){
        return building;
    }

    string getStreet(){
        return street;
    }

    string getCity(){
        return city;
    }

    int getPin(){
        return pin;
    }

    void accept(){
        cout << "Enter building: "<< endl;
        cin >> building;
        cout << "Enter street: "<< endl;
        cin >> street;
        cout << "Enter city: "<< endl;
        cin >> city;
        cout << "Enter pin: "<< endl;
        cin >> pin;
    }

    void display(){
        cout << "Building: " << building << endl;
        cout << "Street: " << street <<endl;
        cout << "City: "<< city <<endl;
        cout << "Pin: "<< pin <<endl;
    }

};
int main(){
    Address a;
    a.setBuilding("Yamuna");
    cout << "Get building: "<< a.getBuilding() << endl;

    a.setStreet("Sawarkar road");
    cout << "Get street: "<< a.getStreet() << endl;

    a.setCity("Aurangabad");
    cout << "Get city: "<< a.getCity() << endl;

    a.setPin(431001);
    cout<<"Get pin: "<< a.getPin() << endl;

    string building;
    string street; 
    string city;
    int pin;
    Address a1(building, street,city,pin);
    a1.accept();
    a1.display();
   
    return 0;
     
}