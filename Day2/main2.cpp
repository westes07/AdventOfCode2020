#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool isValid(char search, string contents, int pos1, int pos2){
    if (contents[pos1] == search){
        if(contents[pos2] != search){
            return true;
        }
    } else if(contents[pos2] == search){
        return true;
    }
    return false;
}

int main(){
    vector<int> lines;
    ifstream in;
    in.open("AdventOfCode2.txt");
    string line;
    char search;
    int count = 0, pos1, pos2;
    while (getline(in, line)){
        pos1 = stoi(line.substr(0, line.find('-'))) - 1;
        line = line.substr(line.find('-')+1);
        pos2 = stoi(line.substr(0, line.find(' '))) - 1;
        line = line.substr(line.find(' ')+1);
        search = line[0];
        line = line.substr(line.find(' ') + 1);
        if (isValid(search, line, pos1, pos2)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}