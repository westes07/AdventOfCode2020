#include <fstream>
#include <iostream>
#include "graph.hpp"

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode10.txt");
    List list;
    
    string line;

    while (getline(in, line)){
        list.addAdapter(stoi(line));
    }
    list.runList();
    graph adapters(list);
    adapters.createConnections();

    cout << adapters.traverse() << endl;
    return 0;
}