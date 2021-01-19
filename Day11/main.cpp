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
    int count = 0;
    while(!stat){
        // if(count == 1){
        //     break;
        // }
        // count++;
        grid.printGrid();
        cout << endl;
        stat = !grid.tick();
    }

    cout << grid.countOccupied() << endl;
    return 0;
}