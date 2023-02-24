#include<iostream>
#include "account.h"
using namespace std;

int main()
{
    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);

    if(frank_account.deposit(200.0)){
        cout << "Deposit OK" << endl;
    }
    else{
        cout << "Deposit Not Allowed" << endl;
    }

    if(frank_account.withdraw(500.0)){
        cout << "Withdrawal OK" << endl;
    }
    else{
        cout << "Not Sufficient Funds" << endl;
    }

    if(frank_account.withdraw(1500.0)){
        cout << "Withdrawal OK" << endl;
    }
    else{
        cout << "Not Sufficient Funds" << endl;
    }
    
    return 0;
}