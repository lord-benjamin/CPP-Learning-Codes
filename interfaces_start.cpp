#include<iostream>
using namespace std;

class Account{
    friend ostream &operator<<(ostream &os,const Account &acc);
public:
    virtual void withdraw(double amount){
        cout << "In Account::withdraw" << endl;
    }
    virtual ~Account(){}
};

ostream &operator<<(ostream &os,const Account &acc){
    os << "Account display";
    return os;
}

class Savings_Account : public Account{
    friend ostream &operator<<(ostream &os,const Savings_Account &acc);
public:
    virtual void withdraw(double amount){
        cout << "In Savings::withdraw" << endl;
    }
    virtual ~Savings_Account(){}
};

ostream &operator<<(ostream &os,const Savings_Account &acc){
    os << "Savings display";
    return os;
}

class Checking_Account : public Account{
    friend ostream &operator<<(ostream &os,const Checking_Account &acc);
public:
    virtual void withdraw(double amount){
        cout << "In Checking::withdraw" << endl;
    }
    virtual ~Checking_Account(){}
};

ostream &operator<<(ostream &os,const Checking_Account &acc){
    os << "Checking display";
    return os;
}

class Trust_Account : public Account{
    friend ostream &operator<<(ostream &os,const Trust_Account &acc);
public:
    virtual void withdraw(double amount){
        cout << "In Trust::withdraw" << endl;
    }
    virtual ~Trust_Account(){}
};

ostream &operator<<(ostream &os,const Trust_Account &acc){
    os << "Trust display";
    return os;
}

int main()
{
    Account *p1 = new Account();
    cout << *p1 << endl;

    Account *p2 = new Checking_Account();
    cout << *p2 << endl;

    cout << endl;
    
    Account a;
    cout << a << endl;
    
    Savings_Account s;
    cout << s << endl;
    
    Checking_Account c;
    cout << c << endl;
    
    Trust_Account t;
    cout << t << endl;
    
    return 0;
}