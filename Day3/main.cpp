#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int countTrees(vector<vector<char> > map){
    int x = 0, y = 0, count = 0;
    while (y < map.size()){
        if (map[y][x] == '#'){
            count++;
        }
        x += 3;
        y += 1;
        if (x >= map[0].size()){
            x -= map[0].size();
        }
    }
    return count;
}

int main(){
    vector<vector<char> > lines;

    ifstream in;
    in.open("AdventOfCode3.txt");
    string read;
    vector<char> line;
    
    while (getline(in, read)){
        line.clear();
        for (int i = 0; i < read.length(); i++){
            line.push_back(read[i]);
        }
        lines.push_back(line);
    }

    cout << countTrees(lines) << endl;
    return 0;
}