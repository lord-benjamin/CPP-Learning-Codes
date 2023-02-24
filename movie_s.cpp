#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Movie{
private:
    string name;
    string rating;
    int watched;
public:
    void set_name(string name_val){
        name = name_val;
    }
    string get_name() const{
        return name;
    }
    void set_rating(string rating_val){
        rating = rating_val;
    }
    string get_rating() const{
        return rating;
    }
    void set_watched(int watched_val){
        watched = watched_val;
    }
    int get_watched() const{
        return watched;
    }
    void increment_watched(){
        watched++;
    }
    void display() const{
        cout << name << ", " << rating << ", " << watched << endl;
    }

    Movie(string name,string rating,int watched);
    
    Movie(const Movie &source);
    
    ~Movie();
};

Movie::Movie(string name_val,string rating_val,int watched_val)
    : name{name_val},rating{rating_val},watched{watched_val}{}

Movie::Movie(const Movie &source)
    : Movie(source.name,source.rating,source.watched){}

Movie::~Movie(){}

class Movies{
private:
    vector<Movie> movies;
public:
    bool add_movie(string name_val,string rating_val,int watched_val){
        int count{0};
        for(auto movie:movies){
            if(movie.get_name() == name_val){
                count++;
            }
        }
        
        if(count == 0){
            movies.push_back(Movie(name_val,rating_val,watched_val));
            return true;
        }
        else{
            return false;
        }
        
    }
    bool increment_watched(string name_val){
        int count{0},index{};
        for(int i{0}; i<movies.size(); ++i){
            if(movies[i].get_name() == name_val){
                count++;
                index = i;
            }
        }
        
        if(count == 1){
            movies[index].increment_watched();
            return true;
        }
        else{
            return false;
        }
    }
    void display() const{
        if(movies.empty() == 1){
            cout << "Sorry, no movies to display" << endl << endl;
        }
        else{
            cout << endl << "=========================" << endl;
            for(auto movie:movies){
                movie.display();
            }
            cout << "=========================" << endl << endl;
        }
    }

    Movies();

    Movies(const Movies &source);

    ~Movies();
};

Movies::Movies(){}

Movies::Movies(const Movies &source){}

Movies::~Movies(){}

void increment_watched(Movies &movies,string name);
void add_movie(Movies &movies,string name,string rating,int watched);

void increment_watched(Movies &movies,string name){
    if(movies.increment_watched(name)){
        cout << name << " watch incremented" << endl;
    }
    else{
        cout << name << " not found" << endl;
    }
}

void add_movie(Movies &movies,string name,string rating,int watched){
    if(movies.add_movie(name,rating,watched)){
        cout << name << " added" << endl;
    }
    else{
        cout << name << " already exists" << endl;
    }
}

int main()
{
    Movies my_movies;
    
    my_movies.display();

    add_movie(my_movies,"Big","PG-13",2);
    add_movie(my_movies,"Star Wars","PG",5);
    add_movie(my_movies,"Cinderella","PG",7);

    my_movies.display();

    add_movie(my_movies,"Cinderella","PG",7);
    add_movie(my_movies,"Ice Age","PG",12);

    my_movies.display();

    increment_watched(my_movies,"Big");
    increment_watched(my_movies,"Ice Age");

    my_movies.display();

    increment_watched(my_movies,"Something");

    return 0;
}