#include<iostream>
#include<vector>
using namespace std;

//This class uses dynamic polymorphism for the withdrawal method
class Account{
public:
    virtual void withdraw(double amount){
        cout << "In Account::withdraw" << endl;
    }
    virtual ~Account(){
        cout << "Account::destructor" << endl;
    }
};

class Savings_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Savings::withdraw" << endl;
    }
    virtual ~Savings_Account(){
        cout << "Savings_Account::destructor" << endl;
    }
};

class Checking_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Checking::withdraw" << endl;
    }
    virtual ~Checking_Account(){
        cout << "Checking_Account::destructor" << endl;
    }
};

class Trust_Account : public Savings_Account{
public:
    virtual void withdraw(double amount){
        cout << "In Trust::withdraw" << endl;
    }
    virtual ~Trust_Account(){
        cout << "Trust_Account::destructor" << endl;
    }
};

int main()
{
    cout << "==========Pointers==========" << endl;
    Account *p1 = new Account();
    Account *p2 = new Savings_Account();
    Account *p3 = new Checking_Account();
    Account *p4 = new Trust_Account();

    p1 -> withdraw(1000);
    p2 -> withdraw(1000);
    p3 -> withdraw(1000);
    p4 -> withdraw(1000);

    cout << "\n==========CleanUp==========" << endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}