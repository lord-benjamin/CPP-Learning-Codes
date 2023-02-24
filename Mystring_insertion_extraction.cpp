#include<iostream>
#include<cstring>
using namespace std;

class Mystring{
    friend ostream &operator<<(ostream &os,const Mystring &rhs);
    friend istream &operator>>(istream &in,Mystring &rhs);
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
    cout << "Using copy assignment" << endl;
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
    cout << "Using move assignment" << endl;
    if(this == &rhs){
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
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

//overloaded insertion operator
ostream &operator<<(ostream &os,const Mystring &rhs){
    os << rhs.str;
    return os;
}

//overloaded extraction operator
istream &operator>>(istream &in,Mystring &rhs){
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

int main()
{
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are: " << larry << ", " << moe << ", and " << curly << endl;
    cout << "\nEnter the three stooges names separated by space: ";
    cin >> larry >> moe >> curly;
    cout << "The three stooges are: " << larry << ", " << moe << ", and " << curly << endl;
    
    return 0;
}