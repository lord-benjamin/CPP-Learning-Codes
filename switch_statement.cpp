/*
    Ask the user what grade they expect on an exam
    tell them what they need to score to get it
*/

#include <iostream>
using namespace std;

int main()
{
    char letter_grade{};

    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letter_grade;

    switch(letter_grade){
        case 'a':
        case 'A':
            cout << "You need a 90 or above, study hard!" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You need 80-89 for a B, go study!" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You need 70-79 for an average grade!" << endl;
            break;
        case 'd':
        case 'D':
            cout << "Hmm, you should try for a better grade. All you need is 60-69!" << endl;
            break;
        case 'f':
        case 'F':{            //curly braces used for introducing a variable
            char confirm{};
            cout << "Are you sure (Y/N)? ";
            cin >> confirm;
            if(confirm == 'y' || confirm == 'Y'){
                cout << "OK, I guess you don't wanna study..." << endl;
            }
            else if(confirm == 'n' || confirm == 'N'){
                cout << "Good - go study!" << endl;
            }
            else{
                cout << "Please type, what you are asked for!" << endl;
            }
            break;
        }  
        default:
            cout << "Sorry, not a valid grade!" << endl;
    }
    return 0;
}