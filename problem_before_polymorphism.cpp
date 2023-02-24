#include<iostream>
#include<memory>
using namespace std;

class Base{
public:
    void say_hello() const{
        cout << "Hello - I'm a Base class object" << endl;
    }
};

class Derived : public Base{
public:
    void say_hello() const{
        cout << "Hello - I'm a Derived class object" << endl;
    }
};

void greetings(const Base &obj){
    cout << "Greetings: ";
    obj.say_hello();  //Always bind to Base::say_hello()
}

int main()
{
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    greetings(b);
    greetings(d);

    Base *ptr = new Derived();
    ptr -> say_hello();  //Will bind to Base::say_hello()

    unique_ptr<Base> ptr1 = make_unique<Derived>();  //Smart Pointer
    ptr1 -> say_hello();  //Still bind to Base::say_hello()

    return 0;
}