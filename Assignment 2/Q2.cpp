#include <iostream>
using namespace std;
class tollbooth
{
private:
    unsigned int noOfCars;
    double totalAmt;

public:
    tollbooth()
    {
        noOfCars = 0;
        totalAmt = 0;
    }

    int TotalnoOfCars = 0;
    int newTotal;
    void payingCar()
    {
        noOfCars = noOfCars + 1;
        cout << "No of cars: " << noOfCars << endl;
        totalAmt = noOfCars * 0.50;
        cout << "total amount:" << totalAmt << endl;
    }

    void nopayCar()
    {
        TotalnoOfCars = TotalnoOfCars + 1;
        newTotal = totalAmt;
        cout << "Number of non pay cars: " << TotalnoOfCars << endl;
        cout << "total amount:" << newTotal << endl;
    }
    void printOnConsole()
    {

        cout << "Total amount is: " << totalAmt << endl;
        cout << "No of paying cars: " << noOfCars << endl;
        cout << "No of non paying cars total: " << TotalnoOfCars << endl;
    }
};

int main()
{
    tollbooth t1;
    // t1.printOnConsole();
    int choice;

    do
    {
        cout << "0.Exit " << endl;
        cout << "1. Paying car" << endl;
        cout << "2. Non paying cars" << endl;
        cout << "3. Print on console" << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exit" << endl;
            break;

        case 1:
            t1.payingCar();
            break;

        case 2:
            t1.nopayCar();
            break;

        case 3:
            t1.printOnConsole();
            break;

        default:
            cout << "Wrong Choice";
            break;
        }

    } while (choice != 0);
    return 0;
}