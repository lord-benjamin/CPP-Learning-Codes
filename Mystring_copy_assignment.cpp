#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Mystring{
private:
    char *str;  //pointer to char[] that holds a C-style string
public:
    Mystring();  //No args constructor
    Mystring(const char *s);  //Overloaded constructor
    Mystring(const Mystring &source);  //Copy constructor
    ~Mystring();  //Destructor

    Mystring &operator=(const Mystring &rhs);  //Copy assignment

    void display() const;
    int get_length() const;  //getters
    const char *get_str() const;
};

//No args constructors
Mystring::Mystring()
    :str{nullptr}{
        str = new char[1];
        *str = '\0';
    }

//Overloaded constructor
Mystring::Mystring(const char *s)
    :str(nullptr){
        if(s == nullptr){
            str = new char[1];
            *str = '\0';
        }
        else{
            str = new char[strlen(s) + 1];
            strcpy(str,s);
        }
    }

//Copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}{
        str = new char[strlen(source.str) + 1];
        strcpy(str,source.str);
    }

//Destructor
Mystring::~Mystring(){
        delete [] str;
    }

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    cout << "Copy assignment" << endl;
    if(this == &rhs){
        return *this;
    }
    delete [] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str,rhs.str);
    return *this;
}

//Display method
void Mystring::display() const{
    cout << str << ": " << get_length() << endl;
}

//length getter
int Mystring::get_length() const{
    return strlen(str);
}

//string getter
const char *Mystring::get_str() const{
    return str;
}

int main()
{
    Mystring a{"Hello"};  //overloaded constructor
    Mystring b;           //no args constructor
    b = a;                //copy assignment
                          //b.operator=(a);
    b = "This is a test"; //b.operator=("This is a test")

    Mystring empty;       //no args constructor
    Mystring larry{"Larry"};  //overloaded constructor
    Mystring stooge{larry};   //copy constructor
    Mystring stooges;         //no args constructor

    empty = stooge;       //copy assignment operator

    empty.display();      //Larry: 5
    larry.display();      //Larry: 5
    stooge.display();     //Larry: 5
    empty.display();      //Larry: 5

    stooges = "Larry, Moe, and Curly";
    stooges.display();    //Larry, Moe, and Curly: 21

    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "=====Loop 1=====" << endl;
    for(const Mystring &s: stooges_vec){
        s.display();            //Larry
                                //Moe
                                //Curly
    }
    cout << "=====Loop 2=====" << endl;
    for(Mystring &s: stooges_vec){
        s = "Changed";          //Copy assignment
    }
    cout << "=====Loop 3=====" << endl;
    for(const Mystring &s: stooges_vec){
        s.display();            //Changed
                                //Changed
                                //Changed
    }
    return 0;
}