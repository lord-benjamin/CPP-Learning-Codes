#include<iostream>
using namespace std;

class Move{
private:
    int *data;
public:
    void set_data_value(int d){
        *data = d;
    }
    int get_data_value(){
        return *data;
    }
    //Constructor
    Move(int d);
    //Copy Constructor
    Move(const Move &source);
    //Destructor
    ~Move();
};

Move::Move(int d){
    data = new int;
    *data = d;
}

Move::Move(const Move &source)
    : data(source.data){
        cout << "Copy constructor - shallow copy" << endl;
    }

Move::~Move(){
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Move s){
    cout << s.get_data_value() << endl;
}

int main()
{
    Move obj1{100};
    display_shallow(obj1);

    Move obj2{obj1};
    obj2.set_data_value(1000);
    return 0;
}