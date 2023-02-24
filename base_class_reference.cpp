#include<iostream>
using namespace std;

class Account{
public:
    virtual void withdraw(double amount){
        cout << "In Account::withdraw" << endl;
    }
    virtual ~Account(){}
};

class Savings_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Savings::withdraw" << endl;
    }
    virtual ~Savings_Account(){}
};

class Checking_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Checking::withdraw" << endl;
    }
    virtual ~Checking_Account(){}
};

class Trust_Account : public Savings_Account{
public:
    virtual void withdraw(double amount){
        cout << "In Trust::withdraw" << endl;
    }
    virtual ~Trust_Account(){}
};

void do_withdraw(Account &account,double amount){
    account.withdraw(amount);
}

int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000);     //In Account::withdraw

    Trust_Account t;
    Account &ref1 = t;
    ref1.withdraw(1000);    //In Trust::withdraw

    Account a1;
    Savings_Account a2;
    Checking_Account a3;
    Trust_Account a4;

    do_withdraw(a1,1000);    //In Account::withdraw
    do_withdraw(a2,2000);    //In Savings::withdraw
    do_withdraw(a3,3000);    //In Checking::withdraw
    do_withdraw(a4,4000);    //In Trust::withdraw
    return 0;
}