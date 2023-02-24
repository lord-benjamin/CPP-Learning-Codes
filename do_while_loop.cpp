//Simple Menu system
#include<iostream>
using namespace std;

int main()
{
    char selection{};
    do{
        cout << endl << "***** MENU *****" << endl;
        cout << "1. Pizza" << endl;
        cout << "2. Burger" << endl;
        cout << "3. French Fries" << endl;
        cout << "4. Cold Drink" << endl;
        cout << "Q. QUIT" << endl;
        cout << endl << "Enter your selection: ";
        cin >> selection;

        if(selection == '1'){
            cout << "You chose 1 : Pizza will be delivered to your home as soon as possible!!" << endl;
        }
        else if(selection == '2'){
            cout << "You chose 2 : Burger will be delivered to your home as soon as possible!!" << endl;
        }
        else if(selection == '3'){
            cout << "You chose 3 : French Fries will be delivered to your home as soon as possible!!" << endl;
        }
        else if(selection == '4'){
            cout << "You chose 4 : Cold Drink will be delivered to your home as soon as possible!!" << endl;
        }
        else if(selection == 'q' || selection == 'Q'){
            cout << "Goodbye...Thanks for shopping!" << endl;
        }
        else{
            cout << "Unknown option!! Try again..." << endl;
        }
    }while(selection != 'q' && selection != 'Q');
    return 0;
}