#include<iostream>
#include<string>
#include<memory>
using namespace std;

class IllegalBalanceException{
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
};

class I_Printable{
    friend ostream &operator<<(ostream &os,const I_Printable &obj);
public:
    virtual void print(ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

class Account : public I_Printable{
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name,double balance = def_balance);
    //Account(string name = "Unnamed Account", double balance = 0.0);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(ostream &os) const override{
        os << "[Account: " << name << ": " << balance << "]";
    }
    double get_balance() const;
    virtual ~Account() = default;
};

Account::Account(string name,double balance)
    : name{name},balance{balance}{
        if(balance < 0.0){
            throw IllegalBalanceException();
        }
    }

bool Account::deposit(double amount){
    if(amount < 0){
        return false;
    }
    else{
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount){
    if(balance - amount >= 0){
        balance -= amount;
        return true;
    }
    else{
        return false;
    }
}

double Account::get_balance() const{
    return balance;
}

ostream &operator<<(ostream &os,const Account &account){
    account.print(os);
    return os;
}

class Savings_Account : public Account{
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(string name = def_name,double balance = def_balance,double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream &os) const override{
        os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "%]";
    }
    virtual ~Savings_Account() = default;
};

Savings_Account::Savings_Account(string name,double balance,double int_rate)
    : Account{name,balance},int_rate{int_rate}{}

bool Savings_Account::deposit(double amount){
    amount += (amount*(int_rate/100));
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount){
    return Account::withdraw(amount);
}

ostream &operator<<(ostream &os,const Savings_Account &account){
    account.print(os);
    return os;
}

class Checking_Account : public Account{
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double withdrawal_fee = 1.50;
public:
    Checking_Account(string name = def_name,double balance = def_balance);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream &os) const override{
        os << "[Checking Account: " << name << ": " << balance << "]";
    }
    virtual ~Checking_Account() = default;
};

Checking_Account::Checking_Account(string name,double balance)
    : Account{name,balance}{}

bool Checking_Account::deposit(double amount){
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount){
    return Account::withdraw(amount+withdrawal_fee);
}

ostream &operator<<(ostream &os,const Checking_Account &account){
    account.print(os);
    return os;
}

class Trust_Account : public Savings_Account{
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double threshold_deposit = 5000.0;
    static constexpr int withdrawal_per_year = 3;
    static constexpr double threshold_withdrawal_in_percentage = 0.2;
    static constexpr double bonus = 50.0;
protected:
    int count_of_withdrawals;
public:
    Trust_Account(string name = def_name,double balance = def_balance,double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(ostream &os) const override{
        os << "[Trust Account: " << name << ": " << balance << ", " << int_rate << "%, Withdrawals: " << count_of_withdrawals << "]";
    }
    virtual ~Trust_Account() = default;
};

Trust_Account::Trust_Account(string name,double balance,double int_rate)
    : Savings_Account{name,balance,int_rate},count_of_withdrawals{0}{}

bool Trust_Account::deposit(double amount){
    if(amount >= threshold_deposit){
        amount += bonus;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if(amount < threshold_withdrawal_in_percentage*balance && count_of_withdrawals < withdrawal_per_year){
        ++count_of_withdrawals;
        return Savings_Account::withdraw(amount);
    }
    else{
        return false;
    }
}

ostream &operator<<(ostream &os,const Trust_Account &account){
    account.print(os);
    return os;
}

int main()
{
    try{
        unique_ptr<Account> moes_account = make_unique<Checking_Account>("Moe",-10.0);
        cout << *moes_account << endl;
    }
    catch(const IllegalBalanceException &ex){
        cerr << "Couldn't create account - negative balance" << endl;
    }
    cout << "Program completed successfully" << endl;
    return 0;
}