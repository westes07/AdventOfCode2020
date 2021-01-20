#include <fstream>
#include "nav.hpp"

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode12.txt");
    string line;
    Nav GPS;

    arg command;
    while (getline(in, line)){
        command.type = line[0];
        command.magnitude = stoi(line.substr(1));
        GPS.executeArg(command);
    }

    cout << GPS.manhattanDistance() << endl;
    return 0;
}