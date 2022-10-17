#include "../include/sector.hh"

using namespace std;

Sector::Sector(){
    board_size = 100;
    Point p = Point('+',0);
    map = vector<vector<Point>> (board_size,vector<Point>(board_size,p));
}

// Robert Jenkins' 96 bit Mix Function
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}


void Sector::print_sector(){
    for(int i = 0; i < board_size; ++i){
        for(int j = 0; j < board_size; ++j){
            cout << map[i][j].first;
        }
        cout << endl;
    }
}

void Sector::paint_colum(int x, int y){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    int length = rand() %80 + 10;
    if(y + length > board_size){
        for(int j = y; j < board_size; ++j){     
            map[x][j].first = '|';
        }
    }
    else{
        for(int j = y; j < y + length; ++j){     
        map[x][j].first = '|';
    }
    }

}


bool random_generator(int chance,bool last_painted,int seed1, int seed2){
    if(last_painted) chance = 40;
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    int rand_num = rand() %100 + chance;

    if(rand_num > 100) return true;
    return false;

}

void Sector::place_victims(int number_victims){
    for(int i = 0; i < number_victims; ++i){
        srand(mix(clock(), time(NULL), getpid()));
        int x = rand()%board_size;
        srand(mix(clock(), time(NULL), getpid()));
        int y = rand()%board_size;
        Point p;
        p.first = 'V';
        p.second = 0;
        map[x][y] = p;
    }
}

void Sector::generate_avalanche(){
    srand (time(NULL));
    bool victims = rand()%2;
    int number_victims = 0;
    if(victims){
        number_victims = rand()%3 + 1;
    } 
    vector<bool> already_painted (board_size,false);
    int chance = -10;
    bool last_painted = false;
    //int max_width = 20;
    //int width = 0;
    for(int i = 0; i < board_size; ++i){
        if(not already_painted[i]){
            for(int j = 0; j < board_size; ++j){
                bool paint = random_generator(chance,last_painted,i,j);
                bool skip = false;
                /*
                if (paint and width > max_width){
                    paint = false;
                    chance = 1;
                    j += 20;
                }
                */
                if(paint){
                    skip = true;
                    already_painted[i] = true;
                    last_painted = true;
                    paint_colum(i,j);
                }
                else {
                    ++chance;
                    //width = 0;
                }

                if(skip) j += board_size;
            }
            chance = 1;
        }
        chance = 1;
        
    }
    place_victims(number_victims);
    if(not victims) cout << "FALSE" << endl;
}


