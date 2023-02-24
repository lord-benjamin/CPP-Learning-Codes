#include<iostream>
#include<string>
#include<set>
#include<map>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

//Used for Part 1
//Display the word and count from the std::map<std::string,int>
void display_words(const map<string,int> &words){
    cout << setw(12) << left << "\nWord" << setw(7) << right << "Count" << endl;
    cout << "====================================================" << endl;
    for(auto pair : words){
        cout << setw(12) << left << pair.first << setw(7) << right << pair.second << endl;
    }
}

//Used for Part 2
//Display the word and occurrences from the std::map<std::string,std::set<int>>
void display_words(const map<string,set<int>> &words){
    cout << setw(12) << left << "\nWord" << "Occurrences" << endl;
    cout << "====================================================" << endl;
    for(auto pair : words){
        cout << setw(12) << left << pair.first << left << "[ ";
        for(auto i : pair.second){
            cout << i << " ";
        }
        cout << "]" << endl;
    }
}

//This function removes periods, commas, semicolons and colon in a string and returns a clean version
string clean_string(const string &s){
    string result;
    for(char c : s){
        if(c == '.' || c == ',' || c == ';' || c == ':'){
            continue;
        }
        else{
            result += c;
        }
    }
    return result;
}

//Part 1 process the file and builds a map of words and the number of times they occur in the file
void part1(){
    map<string,int> words;
    string line;
    string word;
    ifstream in_file{"D:/dhruv/Coding Dhruv/C++/c++ codes/words.txt"};
    if(in_file){
        while(getline(in_file,line)){
            stringstream ss(line);
            while(ss >> word){
                word = clean_string(word);
                words[word]++;      //increment the word in the map
            }
        }
        in_file.close();
        display_words(words);
    }
    else{
        cerr << "Error opening input file" << endl;
    }
}

//Part 2 process the file and builds a map of words and a set of line numbers in which the word appears
void part2(){
    map<string,set<int>> words;
    string line;
    string word;
    ifstream in_file{"D:/dhruv/Coding Dhruv/C++/c++ codes/words.txt"};
    if(in_file){
        int line_number{0}; 
        while(getline(in_file,line)){
            line_number++;
            stringstream ss(line);
            while(ss >> word){
                word = clean_string(word);
                words[word].insert(line_number);
            }
        }
        in_file.close();
        display_words(words);
    }
    else{
        cerr << "Error opening input file" << endl;
    }
}

int main()
{
    part1();
    part2();
    return 0;
}