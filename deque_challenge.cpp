#include<iostream>
#include<cctype>
#include<deque>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

bool is_palindrome(const string &s){
    deque<char> d;
    for(const auto &elem : s){
        if(isalpha(elem)){
            d.push_back(toupper(elem));
        }
    }
    while(!d.empty()){
        if(d.front() != d.back()){
            break;
        }
        if(d.size() == 1){
            d.pop_back();
        }
        else{
            d.pop_back();
            d.pop_front();
        }
    }
    return d.empty();
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