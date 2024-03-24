/* Q 1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
  Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
  given, allocate stack of size 5.
  Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().*/

#include<iostream>
using namespace std;

class Stack {
private:
   int size;
   int top;
   int *ptr;
public:
   Stack(int size = 5)
   {
    this->size = size;
    top = -1;
    ptr = new int [size];
   }
   void push(int element)
   {
      if(!isFull())
      {
        top ++;
        ptr[top] = element;  
      }
      else
         cout << "Stack Overflow" << endl;
   }
   void pop()
   {
      if(!isEmpty())
      {
         top--;
         cout << "Popped Element :" <<ptr[top] << endl;
         cout << "Element is popped" << endl;
      }
      else
         cout << "Stack underflow" << endl;
   }
   int peek()
   {
     return ptr[top];
   }
   void print()
   {
      for (int i =top; i>=0; i--)
      {
         cout << "Element is :" << ptr[i] << endl;
      }
   }
   bool isEmpty()
   {
      return top == -1;
   }
   bool isFull()
   {
      return top == (size - 1);
   }
   ~Stack()
   {
     delete[] ptr;
     ptr = NULL;
   }

};
int main()
{
   int choice;
   Stack s;

   do{
      cout<<"0.Exit"<<endl;
      cout<<"1.Push"<<endl;
      cout<<"2.Pop"<<endl;
      cout<<"3.Peek"<<endl;
      cout<<"4.Print"<<endl;
      cout<<"Enter your choice:"<<endl;
      cin>>choice;

      switch(choice)
      {
         case 0: cout<< "Thank you"<<endl;
                 break;
         case 1:
                int element;
                cout << "Enter element :" <<endl;
                cin >> element;
                s.push(element);
                break;
         case 2:
                s.pop();
                break;
         case 3:
                cout <<"Peek :" <<s.peek()<<endl;
                break;
         case 4:
                s.print();
                break;
         default:
                cout << "Wrong Choice" << endl;
                break;
               
      }
   }while(choice!=0);
 return 0;
}