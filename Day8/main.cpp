#include "stack.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode8.txt");
    Stack stack;
    string line;

    while (getline(in, line)){
        stack.addArg(line);
    }

    cout << stack.executeStack() << endl;
    
    return 0;
}