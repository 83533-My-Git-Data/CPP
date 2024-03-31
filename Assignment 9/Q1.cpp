/*Q1. Modify assignment 8 – Q1 to save all accounts data into STL vector. Provide additional facility
to display all accounts.*/


#include<iostream>
#include<vector>
using namespace std;

enum EAccountType{
    SAVING = 1,
    CURRENT,
    DMAT
} ;


class InSufficientFundsException
{
private:
    int accno;
    double currentBalance;
    double withdrawAmount;
public:
    InSufficientFundsException()
    {
        accno = 0;
        currentBalance =  0;
        withdrawAmount = 0;

    }
    InSufficientFundsException(int accno, double currentBalance, double withdrawAmount)
    {
        this->accno =accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;
    }
    void display()
    {
        if(currentBalance < withdrawAmount){
            cout << "Exception:" ;
            cout << "Insufficient Amount..."<<endl;
        }
        else if (withdrawAmount < 0){
            cout << "Exception :";
            cout << "Can't withdraw value less than 0"<< endl;
        }
    }
};

class Account
{
private:
    int accno;
    EAccountType type;
    double Balance;
  
public:
    Account()
    {
       int accno = 0;
       EAccountType type = SAVING;
       double Balance = 0;
    }
    Account(int accno, EAccountType Acc_type,double Balance)
    {
       this->accno = accno;
       this->type = type;
       this->Balance = Balance;
    }
    int getAccno(){
        return accno;
    }
    void accept(){
        int choice;
        cout << "1.SAVING"<<endl;
        cout << "2.CURRENT"<<endl;
        cout << "3.DMAT"<<endl;
        cout << "Enter your account type to create:";
        cin >> choice;
        cout << "Enter Account no:"<< endl;
        cin >> accno;
        cout <<"Enter Balance:"<< endl;
        cin >> Balance;
        if (choice <=0 || choice >3)
            throw 1;
        type = EAccountType(choice);
    }
    void display(){
        string EAccountType;
        cout << "Account details"<< endl;
        cout << "Account No:"<< accno << endl;
        switch (type){
            case 1: EAccountType ="SAVING";
                break;
            case 2: EAccountType ="CURRENT";
                break;
            case 3: EAccountType ="DMAT";
                break;
            default :
                break;
        }
        cout << "AccountType:"<< type<< endl;
        cout << "Balance :" << Balance << endl;
    }
    void deposit(double amount)
    {
        if(amount<0)
           throw 1;
        else{
            Balance = amount+Balance;
        }
    }
    void withdraw(double amount){
        cout << "your balance is:" << Balance << endl;
        cout << "Enter amount to withdraw :";
        cin >> amount;
        if (Balance< amount){
           throw InSufficientFundsException(accno, Balance,amount);   
        }  
        else if (amount < 0)
        {
            throw InSufficientFundsException(accno, Balance, amount);
        }
        else{
            Balance =Balance -amount;
        }
               
    }
 };

 int main()
 {
    int ch;
    int index = 0;
    vector<Account *>account_list;
    Account* ptr;
    // Account *ptr[5];

    do{
        cout<<"....Welcome...."<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"1.Add Account details"<<endl;
        cout<<"2.Display Account details"<<endl;
        cout<<"3.Deposit money"<<endl;
        cout<<"4.Withdraw money"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>ch;

        switch (ch)
        {
            case 0 :
                cout << "Thank you " << endl;
                break;
            case 1 :
                ptr = new Account();
                ptr->accept();
                account_list.push_back(ptr);
                 /*if (index < 5)
                 {
                    ptr[index] = new Account();
                    ptr[index]->accept();
                    index++;
                 }
                 else{
                    cout << "Array is full" << endl;
                 }*/
                 break;
            case 2:
                for(int i =0; i<account_list.size();i++)
                {
                    account_list[i]->display();
                }
                /*for(int i = 0; i < index; i++)
                ptr[i]->display();*/
                break;
            case 3:{
               int accno, amount;
               cout<< "Enter accno:";
               cin >> accno;
              //for(int i =0;i<index;i++)
              for (int i = 0; i <account_list.size(); i++)
                {
                    try{
                        // if(ptr[i]->getAccno()==accno)
                        if(account_list[i]->getAccno()==accno)
                         {
                            cout << "Enter Amount to deposit:"<< endl;
                            cin >> amount;
                            account_list[i]->deposit(amount);
                            // ptr[i]->deposit(amount);
                         }
                    }
                    catch(int)
                    {
                        cout << "Invalid amount to deposit"<< endl;
                    }
                }      
              }
              break;
            case 4:{
                int amount, accno;
                cout<< "Enter Accountno:"<< endl;
                cin >> accno;
                // for(int i =0;i<index;i++)
                for(int i =0;i<account_list.size();i++)
                {
                    try{
                        // if(ptr[i]->getAccno()==accno)
                        if(account_list[i]->getAccno()==accno)
                        {
                        cout<<"Enter amount to withdraw:"<< endl;
                        cin >> amount;
                        // ptr[i]->withdraw(amount);
                        account_list[i]->withdraw(amount);
                        }
                    }
                    catch(InSufficientFundsException e)
                    {
                        e.display();
                    }
                }
              }
                 break;
            default :
                  cout << "Invalid choice"<< endl;
                  break;
        }

    }while(ch!=0);
    for(int i =0;i<account_list.size();i++)
    {
        delete account_list[i];
    }
    // for(int i = 0; i < index; i ++)
    //   delete ptr [i];
    return 0;
 }





