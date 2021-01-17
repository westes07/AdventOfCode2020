#include <fstream>
#include "list.hpp"

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode9.txt");
    List numbers;
    string line;
    int count = 0;
    while (getline(in, line)){
        numbers.addNum(stoll(line));
        count++;
    }

    for (int i = 25; i < count; i++) {
        if (!numbers.checkIndex(i)){
            cout << numbers.at(i) << endl;
            break;
        }
        
    }

    return 0;
}