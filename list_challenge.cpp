#include<iostream>
#include<list>
#include<string>
#include<cctype>
#include<iomanip>
#include<limits>
using namespace std;

class Song{
    friend ostream &operator<<(ostream &os,const Song &s);
    string name;
    string artist;
    int rating;
public:
    Song() = default;
    Song(string name,string artist,int rating) : name{name},artist{artist},rating{rating}{}
    string get_name() const{
        return name;
    }
    string get_artist() const{
        return artist;
    }
    int get_rating() const{
        return rating;
    }
    bool operator<(const Song &rhs) const{
        return this->name < rhs.name;
    }
    bool operator==(const Song &rhs) const{
        return this->name == rhs.name;
    }
};

ostream &operator<<(ostream &os,const Song &s){
    os << setw(20) << left << s.name << setw(30) << left << s.artist << setw(2) << left << s.rating;
    return os;
}

void display_menu(){
    cout << "\nF - Play First Song" << endl;
    cout << "N - Play Next Song" << endl;
    cout << "P - Play Previous Song" << endl;
    cout << "A - Add and play a new Song at current location" << endl;
    cout << "L - List the current playlist" << endl;
    cout << "=======================================================" << endl;
    cout << "Enter the selection (Q to quit): ";
}

void play_current_song(const Song &song){
    cout << "Playing:" << endl;
    cout << song << endl;
}

void display_playlist(const list<Song> &playlist,const Song &current_song){
    cout << "\nYour Playlist:" << endl;
    for(const auto &song : playlist){
        cout << song << endl;
    }
    cout << "Current song:" << endl;
    cout << current_song << endl;
}

int main()
{
    list<Song> playlist{
        {"God's Plan","Drake",5},
        {"Never Be The Same","Camila Cabello",5},
        {"Pray For Me","The Weekend and K. Lamar",4},
        {"The Middle","Zedd, Maren Morris & Grey",5},
        {"Wait","Maroone 5",4},
        {"Whatever It Takes","Imagine Dragons",3}
    };
    list<Song>::iterator current_song = playlist.begin();
    char choice{};
    display_playlist(playlist,*current_song);
    do{
        display_menu();
        cin >> choice;
        if(choice == 'F' || choice == 'f'){
            cout << "Playing first song" << endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        }
        else if(choice == 'N' || choice == 'n'){
            cout << "Playing next song" << endl;
            advance(current_song,+1);
            if(current_song == playlist.end()){
                current_song = playlist.begin();
                cout << "Wrapping to start of playlist" << endl;
            }
            play_current_song(*current_song);
        }
        else if(choice == 'P' || choice == 'p'){
            cout << "Playing previous song" << endl;
            if(current_song == playlist.begin()){
                current_song = playlist.end();
                advance(current_song,-1);
                cout << "Wrapping to end of playlist" << endl;
            }
            else{
                advance(current_song,-1);
            }
            play_current_song(*current_song);
        }
        else if(choice == 'A' || choice == 'a'){
            cout << "Adding and playing new song" << endl;
            string new_song;
            string new_artist;
            int new_rating;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter song name: ";
            getline(cin,new_song);
            cout << "Enter song artist: ";
            getline(cin,new_artist);
            cout << "Enter your rating (1-5): ";
            cin >> new_rating;
            playlist.insert(current_song,Song{new_song,new_artist,new_rating});
            advance(current_song,-1);
            play_current_song(*current_song);
        }
        else if(choice == 'L' || choice == 'l'){
            display_playlist(playlist,*current_song);
        }
        else if(choice == 'Q' || choice == 'q'){
            cout << "Goodbye...Exiting Song Player..." << endl;
        }
        else{
            cout << "Sorry...Incorrect Selection...Try Again..." << endl;
        }
    }while(choice != 'Q' && choice != 'q');
    return 0;
}