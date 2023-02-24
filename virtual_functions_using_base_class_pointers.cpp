#include<iostream>
#include<vector>
using namespace std;

//This class uses dynamic polymorphism for the withdrawal method
class Account{
public:
    virtual void withdraw(double amount){
        cout << "In Account::withdraw" << endl;
    }
};

class Savings_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Savings::withdraw" << endl;
    }
};

class Checking_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Checking::withdraw" << endl;
    }
};

class Trust_Account : public Savings_Account{
public:
    virtual void withdraw(double amount){
        cout << "In Trust::withdraw" << endl;
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

    cout << "==========Array==========" << endl;
    Account *array[] = {p1,p2,p3,p4};
    for(auto i{0}; i<4; ++i){
        array[i] -> withdraw(1000);
    }

    cout << "\n==========Vector==========" << endl;
    vector<Account*> accounts {p1,p2,p3,p4};
    for(auto acc_ptr : accounts){
        acc_ptr -> withdraw(1000);
    }

    cout << "\n==========Vector==========" << endl;
    accounts.push_back(p4);
    accounts.push_back(p4);
    for(auto acc_ptr : accounts){
        acc_ptr -> withdraw(1000);
    }

    cout << "\n==========CleanUp==========" << endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}