#include<iostream>
#include<vector>
#include<string>
using namespace std;

void display(const vector<string> *const v){
    // (*v).at(0) = "Funny";  Will give error
    for(auto str:*v){
        cout << str << " ";
    }
    cout << endl;
    // v = nullptr;  Will give error
}

void display(int *array,int sentinel){
    while(*array != sentinel){
        cout << *array++ << " ";
    }
    cout << endl;
}

int main()
{
    cout << "----------------------------" << endl;
    vector<string> stooges{"Larry","Moe","Curly"};
    display(&stooges);

    cout << "----------------------------" << endl;
    int scores[]{100,98,97,79,85,-1};
    display(scores,-1);

    return 0;
}