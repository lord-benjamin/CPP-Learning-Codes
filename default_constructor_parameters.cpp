#include<iostream>
#include<string>
using namespace std;

class Player{
private:
    string name;
    int health;
    int xp;
public:
    Player(string name_val = "None",int health_val = 0,int xp_val = 0);
    // Player(); provides ambiguity, compiler thinks whether to call the three-args constructor or this one
};

Player::Player(string name_val,int health_val,int xp_val)
    : name{name_val},health{health_val},xp{xp_val}{
        cout << "Three-args constructor called" << endl;
}

int main()
{
    Player empty;
    Player frank{"Frank"};
    Player hero{"Hero",100};
    Player villain{"Villain",100,55};
    return 0;
}