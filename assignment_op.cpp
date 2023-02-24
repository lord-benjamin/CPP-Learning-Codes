#include <iostream>
using namespace std;

int main()
{
    int num1 {10};
    int num2 {20};
    const int num3 {30};
    
    //num1 = 40;  //assigns 30 to num1
    
    //Errors:
    //100 = num1;  //will not assign num1 to 100!!
    //num1 = "Frank";  //will not assign a string to int value
    //num3 = 100;  //will not assign 100 to num3 as num3 is a constant

    num1 = num2 = 1000;  //will first assign 1000 to num2 and then num2 to num1

    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;
    return 0;
}