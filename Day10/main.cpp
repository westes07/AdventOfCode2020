#include <fstream>
#include "list.hpp"

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode10.txt");
    List adapters;
    string line;

    while (getline(in, line)){
        adapters.addAdapter(stoi(line));
    }

    adapters.runList();

    return 0;
}