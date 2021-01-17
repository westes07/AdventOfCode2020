#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool isValid(char search, string contents, int min, int max){
    int count = 0;
    for (int i = 0; i < contents.length(); i++){
        if (contents[i] == search){
            count++;
        }
    }
    if (count >= min && count <= max){
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
    int count = 0, min, max;
    while (getline(in, line)){
        min = stoi(line.substr(0, line.find('-')));
        line = line.substr(line.find('-')+1);
        max = stoi(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ')+1);
        search = line[0];
        line = line.substr(line.find(' ') + 1);
        if (isValid(search, line, min, max)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}