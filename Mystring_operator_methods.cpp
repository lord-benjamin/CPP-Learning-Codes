#include<iostream>
#include<cstring>
using namespace std;

class Mystring{
private:
    char *str;  //pointer to char[] that holds a C-style string
public:
    Mystring();  //No args constructor
    Mystring(const char *s);  //Overloaded constructor
    Mystring(const Mystring &source);  //Copy constructor
    Mystring(Mystring &&source);  //Move constructor
    ~Mystring();  //Destructor

    Mystring &operator=(const Mystring &rhs);  //Copy assignment
    Mystring &operator=(Mystring &&rhs);       //Move assignment

    Mystring operator-() const;                       //make lowercase
    Mystring operator+(const Mystring &rhs) const;    //concatenate
    bool operator==(const Mystring &rhs) const;       //compare

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
        cout << "Copy constructor used" << endl;
    }

//Move constructor
Mystring::Mystring(Mystring &&source)
    :str{source.str}{
        source.str = nullptr;
    }

//Destructor
Mystring::~Mystring(){
        delete [] str;
    }

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    if(this == &rhs){
        return *this;
    }
    delete [] this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str,rhs.str);
    return *this;
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&rhs){
    if(this == &rhs){
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Equality
bool Mystring::operator==(const Mystring &rhs) const{
    return (strcmp(str,rhs.str) == 0);
}

//Make lowercase
Mystring Mystring::operator-() const{
    char *buff = new char[strlen(str) + 1];
    strcpy(buff,str);
    for(size_t i{0}; i<strlen(buff); ++i){
        buff[i] = tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//Concatenation
Mystring Mystring::operator+(const Mystring &rhs) const{
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff,str);
    strcat(buff,rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
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
    cout << boolalpha << endl;
    
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();  //Larry
    moe.display();    //Moe

    cout << (larry == moe) << endl;  //false
    cout << (larry == stooge) << endl;  //true

    larry.display();           //Larry
    Mystring larry2 = -larry;
    larry2.display();          //larry

    Mystring stooges = larry + "Moe";   //ok with member function  
    //Mystring stooges = "Larry" + moe;   //Compiler error

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();   //Moe Larry

    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();   //Moe Larry Curly
    return 0;
}