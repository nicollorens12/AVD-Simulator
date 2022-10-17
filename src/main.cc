#include "../include/sector.hh"

using namespace std;

int main(){
    Sector mapa;
    mapa.generate_avalanche();
    mapa.print_sector();
}