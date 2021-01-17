#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int countTrees(vector<vector<char> > map, int changeX, int changeY){
    int x = 0, y = 0, count = 0;
    while (y < map.size()){
        if (map[y][x] == '#'){
            count++;
        }
        x += changeX;
        y += changeY;
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

    int trees[5] = {countTrees(lines, 1, 1), countTrees(lines, 3, 1), countTrees(lines, 5, 1),
    countTrees(lines, 7, 1), countTrees(lines, 1, 2)};
    int product = 1;

    for (int i = 0; i < 5; i++){
        cout << trees[i] << endl;
        product = product * trees[i];
    }
    

    cout << "====" << product << "====" << endl;

    return 0;
}