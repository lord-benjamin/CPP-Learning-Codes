#include<iostream>
#include<cstring>
using namespace std;

class Mystring{
    friend bool operator==(const Mystring &lhs,const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs,const Mystring &rhs);
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

//Equality
bool operator==(const Mystring &lhs,const Mystring &rhs){
    return (strcmp(lhs.str,rhs.str) == 0);
}

//Make lowercase
Mystring operator-(const Mystring &obj){
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff,obj.str);
    for(size_t i{0}; i<strlen(buff); ++i){
        buff[i] = tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//Concatenation
Mystring operator+(const Mystring &lhs,const Mystring &rhs){
    size_t buff_size{strlen(lhs.str) + strlen(rhs.str) + 1};
    char *buff = new char[buff_size];
    strcpy(buff,lhs.str);
    strcat(buff,rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

int main()
{
    Mystring larry{"Larry"};
    larry.display();               //Larry
    
    larry = -larry;
    larry.display();               //larry

    cout << boolalpha << endl;

    Mystring moe{"Moe"};
    Mystring stooge = larry;

    cout << (larry == moe) << endl;  //false
    cout << (larry == stooge) << endl;  //true
    
    // Mystring stooges = larry + "Moe";
    Mystring stooges = "Larry" + moe;   //now ok with non-member function
    stooges.display();    //LarryMoe

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();   //Moe Larry

    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();   //Moe larry Curly
    return 0;
}