#include <iostream>
using namespace std;

int main()
{
    enum Direction{
        left,right,up,down
    };

    Direction heading{};

    switch(heading){
        case left:
            cout << "Going left" << endl;  //without break;
        case right:
            cout << "Going right" << endl;  //without break;
        default:
            cout << "OK" << endl;
    }
    return 0;
}