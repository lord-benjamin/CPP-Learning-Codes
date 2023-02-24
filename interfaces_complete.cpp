#include<iostream>
using namespace std;

class I_Printable{
    friend ostream &operator<<(ostream &os,const I_Printable &obj);
public:
    virtual void print(ostream &os) const = 0;
};

ostream &operator<<(ostream &os,const I_Printable &obj){
    obj.print(os);
    return os;
}

class Account : public I_Printable{
public:
    virtual void withdraw(double amount){
        cout << "In Account::withdraw" << endl;
    }
    virtual void print(ostream &os) const override{
        os << "Account display";
    }
    virtual ~Account(){}
};

class Savings_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Savings::withdraw" << endl;
    }
    virtual void print(ostream &os) const override{
        os << "Savings display";
    }
    virtual ~Savings_Account(){}
};

class Checking_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Checking::withdraw" << endl;
    }
    virtual void print(ostream &os) const override{
        os << "Checking display";
    }
    virtual ~Checking_Account(){}
};

class Trust_Account : public Account{
public:
    virtual void withdraw(double amount){
        cout << "In Trust::withdraw" << endl;
    }
    virtual void print(ostream &os) const override{
        os << "Trust display";
    }
    virtual ~Trust_Account(){}
};

class Dog : public I_Printable{
public:
    virtual void print(ostream &os) const override{
        os << "Woof Woof";
    }
};

void print(I_Printable &obj){
    cout << obj << endl;
}

int main()
{
    Dog *dog  = new Dog();
    cout << *dog << endl;

    print(*dog);

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