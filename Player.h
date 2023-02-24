#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<string>
using namespace std;

class Player{
private:
    static int num_players;
    string name;
    int health;
    int xp;
public:
    string get_name(){
        return name;
    }
    int get_health(){
        return health;
    }
    int get_xp(){
        return xp;
    }
    Player(string name_val = "None",int health_val = 0,int xp_val = 0);
    //Copy Constructor
    Player(const Player &source);
    //Destructor
    ~Player();
    static int get_num_players();
};

#endif