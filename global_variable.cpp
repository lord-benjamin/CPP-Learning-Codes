#include <iostream>
using namespace std;

int age {18};   /*declaring and initializing a Global Variable
                  (will not get printed as 1st priority local variable)*/
int main()
{
    int age {16};   /*declaring and initializing a Local Variable
                      (if not there then turn of global)*/
    cout << age << endl;
    return 0;
}