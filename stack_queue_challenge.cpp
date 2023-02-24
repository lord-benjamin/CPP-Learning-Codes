#include<iostream>
#include<cctype>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

bool is_palindrome(const string &s){
    stack<char> sk;
    queue<char> qe;
    for(const auto &elem : s){
        if(isalpha(elem)){
            sk.push(toupper(elem));
            qe.push(toupper(elem));
        }
    }
    while(!qe.empty() && !sk.empty()){
        if(qe.front() != sk.top()){
            break;
        }
        sk.pop();
        qe.pop();
    }
    return sk.empty();
}

int main()
{
    vector<string> test_strings{"a","aba","abba","abbcbba","ab","abc","radar","bob","ana","avid diva","Amore, Roma","A Toyota's a toyota","A Santa at NASA","C++","A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!","This a palindrome","palindrome"};

    cout << boolalpha;
    cout << setw(8) << left << "Result" << "String" << endl;
    for(const auto &s : test_strings){
        cout << setw(8) << left << is_palindrome(s) << s << endl;
    }
    return 0;
}