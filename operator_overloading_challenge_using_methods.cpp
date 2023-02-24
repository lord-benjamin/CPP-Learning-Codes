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

    ostream &operator<<(ostream &os);
    istream &operator>>(istream &in);

    bool operator==(const Mystring &rhs);
    bool operator!=(const Mystring &rhs);
    bool operator<(const Mystring &rhs);
    bool operator>(const Mystring &rhs);

    Mystring operator-();
    Mystring operator+(const Mystring &rhs);
    Mystring operator*(int num);

    Mystring &operator+=(const Mystring &rhs);
    Mystring &operator*=(int num);

    Mystring operator++();      //pre
    Mystring operator++(int);   //post

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
    os << rhs.get_str();
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

//equality
bool Mystring::operator==(const Mystring &rhs){
    return (strcmp(str,rhs.str) == 0);
}

//not equality
bool Mystring::operator!=(const Mystring &rhs){
    return (strcmp(str,rhs.str) != 0);
}

//less than
bool Mystring::operator<(const Mystring &rhs){
    return (strcmp(str,rhs.str) < 0);
}

//greater than
bool Mystring::operator>(const Mystring &rhs){
    return (strcmp(str,rhs.str) > 0);
}

//make lowercase
Mystring Mystring::operator-(){
    char *buff = new char[strlen(str) + 1];
    strcpy(buff,str);
    for(size_t i{0}; i<strlen(buff); ++i){
        buff[i] = tolower(buff[i]);
    }
    Mystring temp{buff};
    delete buff;
    return temp;
}

//concatenation
Mystring Mystring::operator+(const Mystring &rhs){
    size_t buff_size{strlen(str) + strlen(rhs.str) + 1};
    char *buff = new char[buff_size];
    strcpy(buff,str);
    strcat(buff,rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//repetition
Mystring Mystring::operator*(int num){
    size_t buff_size{(strlen(str)*num) + 1};
    char *buff = new char[buff_size];
    strcpy(buff,str);
    for(size_t i{1}; i<num; ++i){
        strcat(buff,str);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

//concatenate in the previous string
Mystring &Mystring::operator+=(const Mystring &rhs){
    *this = *this + rhs.str;
    return *this;
}

//repeat in the previous string
Mystring &Mystring::operator*=(int num){
    *this = *this * num;
    return *this;
}

//pre-increment
Mystring Mystring::operator++(){
    for(size_t i{0}; i<strlen(str); ++i){
        str[i] = toupper(str[i]);
    }
    return *this;
}

//post-increment
Mystring Mystring::operator++(int){
    Mystring temp{*this};
    operator++();
    return temp;
}

int main()
{
    cout << boolalpha;

    Mystring a{"frank"};
    Mystring b{"frank"};

    cout << (a == b) << endl;    //true
    cout << (a != b) << endl;    //false

    b = "george";
    cout << (a == b) << endl;    //false
    cout << (a != b) << endl;    //true
    cout << (a < b) << endl;    //true
    cout << (a > b) << endl;    //false

    Mystring s1{"FRANK"};
    s1 = -s1;
    cout << s1 << endl;      //frank

    s1 = s1 + "*****";
    cout << s1 << endl;        //frank*****

    s1 += "-----";
    cout << s1 << endl;        //frank*****-----

    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;        //123451234512345

    Mystring s3{"abcdef"};
    s3 *= 5;
    cout << s3 << endl;        //abcdefabcdefabcdefabcdefabcdef

    Mystring s{"Frank"};
    ++s;
    cout << s << endl;         //FRANK

    s = -s;
    cout << s << endl;         //frank

    Mystring result;
    result = ++s;
    cout << s << endl;         //FRANK
    cout << result << endl;    //FRANK

    s = "Frank";
    s++;
    cout << s << endl;         //FRANK

    s = -s;
    cout << s << endl;         //frank
    result = s++;
    cout << s << endl;         //FRANK
    cout << result << endl;    //frank

    return 0;
}