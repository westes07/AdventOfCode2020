#include <fstream>
#include "grid.hpp"

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode11.txt");
    Ferry grid;
    string line;
    while (getline(in, line)){
        grid.readLine(line);
    }
    bool stat = false;
    while(!stat){
        stat = grid.tick();
    }

    cout << grid.countOccupied() << endl;
    return 0;
}