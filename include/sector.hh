#ifndef SECTOR_H_
#define SECTOR_H_

#include <vector>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <vector>


// AVALANCHE SIMULATOR
/*
    We will generate a random avalanche, avalanche affected points will be marked as A, with their corresponding height, values.
    Non-Affected point will be marked as S we could add a D type to mark dangerous point. V is a victim of the avalanche.

    A point consists on the type of floor (+, | , D or V) and its height (from sea mesure)

*/
using namespace std;
typedef pair<char,int> Point; 
typedef vector<std::vector<Point>> Map;

class Sector{
    private:
    Map map;
    int board_size;
    int number_victims;
    vector<pair<int,int>> placed;
    
    public:
    Sector();
    void generate_avalanche();
    void print_sector();
    void paint_colum(int x, int y);
    void place_victims(int number_victims);
    pair<int,int> random_coord();

};

#endif