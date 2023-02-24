#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Account{
    friend ostream &operator<<(ostream &os,const Account &account);
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name,double balance = def_balance);
    //Account(string name = "Unnamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

Account::Account(string name,double balance)
    : name{name},balance{balance}{}

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
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}

class Savings_Account : public Account{
    friend ostream &operator<<(ostream &os,const Savings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(string name = def_name,double balance = def_balance,double int_rate = def_int_rate);
    bool deposit(double amount);
    //Inherits the Account::withdraw method
};

Savings_Account::Savings_Account(string name,double balance,double int_rate)
    : Account{name,balance},int_rate{int_rate}{}

bool Savings_Account::deposit(double amount){
    amount += (amount*(int_rate/100));
    return Account::deposit(amount);
}

ostream &operator<<(ostream &os,const Savings_Account &account){
    os << "[Savings_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

class Checking_Account : public Account{
    friend ostream &operator<<(ostream &os,const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double withdrawal_fee = 1.50;
public:
    Checking_Account(string name = def_name,double balance = def_balance);
    //Inherits deposit function from Account class
    bool withdraw(double amount);
};

Checking_Account::Checking_Account(string name,double balance)
    : Account{name,balance}{}

bool Checking_Account::withdraw(double amount){
    return Account::withdraw(amount+withdrawal_fee);
}

ostream &operator<<(ostream &os,const Checking_Account &account){
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}

class Trust_Account : public Savings_Account{
    friend ostream &operator<<(ostream &os,const Trust_Account &account);
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
    bool deposit(double amount);
    bool withdraw(double amount);
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
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%, Withdrawals: " << account.count_of_withdrawals << "]";
    return os;
}

//Utility helper functions for Account class
void display(const vector<Account> &accounts);
void deposit(vector<Account> &accounts,double amount);
void withdraw(vector<Account> &accounts,double amount);

//Utility helper functions for Savings_Account class
void display(const vector<Savings_Account> &accounts);
void deposit(vector<Savings_Account> &accounts,double amount);
void withdraw(vector<Savings_Account> &accounts,double amount);

//Utility helper functions for Checking_Account class
void display(const vector<Checking_Account> &accounts);
void deposit(vector<Checking_Account> &accounts,double amount);
void withdraw(vector<Checking_Account> &accounts,double amount);

//Utility helper functions for Trust_Account class
void display(const vector<Trust_Account> &accounts);
void deposit(vector<Trust_Account> &accounts,double amount);
void withdraw(vector<Trust_Account> &accounts,double amount);

//Helper functions for Account class

//Display Account objects in a vector of Account objects
void display(const vector<Account> &accounts){
    cout << "\n========================Accounts========================" << endl;
    for(const auto &acc : accounts){
        cout << acc << endl;
    }
}

//Deposits supplied amount to each Account object in the vector
void deposit(vector<Account> &accounts,double amount){
    cout << "\n========================Depositing to Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.deposit(amount)){
            cout << "Deposited " << amount << " to " << acc << endl;
        }
        else{
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
        }
    }
}

//Withdraw amount from each Account abject in the vector
void withdraw(vector<Account> &accounts,double amount){
    cout << "\n========================Withdrawing from Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.withdraw(amount)){
            cout << "Withdrew " << amount << " from " << acc << endl;
        }
        else{
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
        }
    }
}

//Helper functions for Savings_Account class

//Display Account objects in a vector of Savings_Account objects
void display(const vector<Savings_Account> &accounts){
    cout << "\n========================Savings Accounts========================" << endl;
    for(const auto &acc : accounts){
        cout << acc << endl;
    }
}

//Deposits supplied amount to each Savings_Account object in the vector
void deposit(vector<Savings_Account> &accounts,double amount){
    cout << "\n========================Depositing to Savings Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.deposit(amount)){
            cout << "Deposited " << amount << " to " << acc << endl;
        }
        else{
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
        }
    }
}

//Withdraw amount from each Savings_Account abject in the vector
void withdraw(vector<Savings_Account> &accounts,double amount){
    cout << "\n========================Withdrawing from Savings Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.withdraw(amount)){
            cout << "Withdrew " << amount << " from " << acc << endl;
        }
        else{
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
        }
    }
}

//Helper functions for Checking_Account class

//Display Account objects in a vector of Checking_Account objects
void display(const vector<Checking_Account> &accounts){
    cout << "\n========================Checking Accounts========================" << endl;
    for(const auto &acc : accounts){
        cout << acc << endl;
    }
}

//Deposits supplied amount to each Checking_Account object in the vector
void deposit(vector<Checking_Account> &accounts,double amount){
    cout << "\n========================Depositing to Checking Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.deposit(amount)){
            cout << "Deposited " << amount << " to " << acc << endl;
        }
        else{
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
        }
    }
}

//Withdraw amount from each Checking_Account abject in the vector
void withdraw(vector<Checking_Account> &accounts,double amount){
    cout << "\n========================Withdrawing from Checking Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.withdraw(amount)){
            cout << "Withdrew " << amount << " from " << acc << endl;
        }
        else{
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
        }
    }
}

//Helper functions for Trust_Account class

//Display Account objects in a vector of Trust_Account objects
void display(const vector<Trust_Account> &accounts){
    cout << "\n========================Trust Accounts========================" << endl;
    for(const auto &acc : accounts){
        cout << acc << endl;
    }
}

//Deposits supplied amount to each Trust_Account object in the vector
void deposit(vector<Trust_Account> &accounts,double amount){
    cout << "\n========================Depositing to Trust Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.deposit(amount)){
            cout << "Deposited " << amount << " to " << acc << endl;
        }
        else{
            cout << "Failed Deposit of " << amount << " to " << acc << endl;
        }
    }
}

//Withdraw amount from each Trust_Account abject in the vector
void withdraw(vector<Trust_Account> &accounts,double amount){
    cout << "\n========================Withdrawing from Trust Accounts========================" << endl;
    for(auto &acc : accounts){
        if(acc.withdraw(amount)){
            cout << "Withdrew " << amount << " from " << acc << endl;
        }
        else{
            cout << "Failed Withdrawal of " << amount << " from " << acc << endl;
        }
    }
}

int main()
{
    cout.precision(2);
    cout << fixed;

    //Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe",2000});
    accounts.push_back(Account{"Curly",5000});

    display(accounts);
    deposit(accounts,1000);
    withdraw(accounts,2000);

    //Savings
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman",2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman",5000,5.0});

    display(sav_accounts);
    deposit(sav_accounts,1000);
    withdraw(sav_accounts,2000);

    //Checking
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{"Kirk"});
    check_accounts.push_back(Checking_Account{"Spock",2000});
    check_accounts.push_back(Checking_Account{"Bones",5000});

    display(check_accounts);
    deposit(check_accounts,1000);
    withdraw(check_accounts,2000);

    //Trust
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account{});
    trust_accounts.push_back(Trust_Account{"Athos",10000.0,5.0});
    trust_accounts.push_back(Trust_Account{"Porthos",20000.0,4.0});
    trust_accounts.push_back(Trust_Account{"Aramis",30000.0});

    display(trust_accounts);
    deposit(trust_accounts,1000);
    withdraw(trust_accounts,3000);

    //Withdraw 5 times from each trust account
    //All withdrawals should fail if there are too many withdrawals or if the withdrawal is >20% of the balance
    for(int i{1}; i<=5; ++i){
        withdraw(trust_accounts,1000);
    }
    return 0;
}