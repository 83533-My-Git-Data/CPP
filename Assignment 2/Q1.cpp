#include<iostream>
using namespace std;

class Box {
private :
    int length;
    int width;
    int height;
public :
    Box()
    {
       cout << " Inside parameterless Constructor" << endl;
       length = 1;
       width = 1;
       height =1;
    }

    Box (int length, int width, int height)
    {
        cout << " Inside parameterized constructor" << endl;
        this-> length = length;
        this-> width = width;
        this-> height = height;
    }

    Box (int value) 
    {
        cout << " Inside single parameterized " << endl;
        length = value;
        width = value;
        height = value;

    } 
    void calculateVolume(){
        int volume = length*width*height;
        cout << "Volume of the box :" << volume << endl;    
    }

};

int main (){
    int choice;
    int length, width, height,value;

    do{
        cout << "0.EXIT" << endl;
        cout << "1.Calculate Volume with default values"<<endl;
        cout << "2.Calculate Volume with length,width and height with same value"<<endl;
        cout << "3.Calculate Volume with different length,width and height values."<<endl;
        cout << "4.Enter the choice"<< endl;
        cin >> choice;

        switch(choice)
        {
            case 0:
            {
               cout << "Exit" <<endl;
            }
            break;
            case 1:
            {
                Box b1;
                b1.calculateVolume();
            }
            break;
            case 2:
            {
                cout << "Enter value" << endl;
                cin >> value;
                Box b2(value);
                b2.calculateVolume();; 
            }
            break;
            case 3:
            {
                int length;
                int width;
                int height;
                cout << "length :"<< endl;
                cin >> length;
                cout << "width :"<< endl;
                cin >> width;
                cout << "height :"<< endl;
                cin >> height;
                Box b3(length,width, height);
                b3.calculateVolume();
            }
            break;
            default: 
               cout << "Enter wrong choice" << endl;
                
        }
 
    }while (choice!=0);
    return 0;
}

