/*Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]*/

#include<iostream>
using namespace std;

class Product{
    int id;
    string title;
    double price;
public:
    virtual void accept(){
     cout << "Enter product Id:"<<endl;
     cin >> id;
     cout << "Enter title :"<< endl;
     getline(cin >>ws, title);
     cout << "Enter price :"<< endl;
     cin >> price;

    }
    virtual void display(){
    cout << "Id :" <<id<< endl<< "title:"<<title <<endl<< "Price:"<< price<< endl;
    }
    double getPrice(){
        return price;
    }
    void setPrice(double price){
        this->price = price;
    }   
};

class Book : public Product{
private:
    string author;
public:
    void accept(){
    Product :: accept();
    cout << "Name of author :" << endl;
    cin >> author;
    cout << "Details of Book:"<< endl;
    setPrice(getPrice()-(getPrice()*0.1));

    }
    virtual void display(){
    Product :: display();
    cout << "Author :"<< author<<endl;
    
    }
};

class Tape : public Product{
private :
    string artist;
public:
    void accept(){
        Product ::accept();
        cout << "Name of Artist:"<<endl;
        cin >> artist;
        cout <<"Details of Tape :"<<endl;
        setPrice(getPrice()-(getPrice()*0.05));
    }
    virtual void display(){
        Product::display();
        cout << "Artist :"<<artist<< endl;

    }
};

int main(){
    int choice;
    Product *arr[5];
    int index =0;
    int total = 0;
    do{
        cout << "0.Exit" << endl;
        cout << "1. Accept book details:" << endl;
        cout << "2. Accept Tape details:" << endl;
        cout << "3. Display total:"<< endl;
        cout << "Enter choice :"<<endl;
        cin >> choice;

        switch (choice)
        {
            case 0:
                cout << "Thank you" << endl;
                break;
            case 1:
                if (index<3)
                {
                    arr[index] = new Book();
                    arr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full.."<<endl;
                }
                break;
            case 2:
                if (index<3)
                {
                    arr[index] = new Tape();
                    arr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "Array is full.."<<endl;
                }
                break;
            case 3:
                for(int i=0;i<index;i++)
                {
                    total = total + arr[i]->getPrice();
                    cout<<"Total price:"<<total<<endl;
                }
                for(int i=0; i<index;i++)
                {
                    arr[i]->display();
                }
                break;

            default:
                cout << "Wrong Choice:"<<endl;
                break;
        };
      
    }while(choice!=0);
    for (int i =0; i<index;i++)
    delete arr[i];

    return 0;
}  



   
