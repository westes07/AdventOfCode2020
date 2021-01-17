//
// Created by Corbin Estes on 12/1/20.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int get_num(vector<int> lines, int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                if (lines[j]+lines[i]+lines[k] == 2020){
                    return (lines[j]*lines[i])*lines[k];
                }
            }
        }
    }
}

int main(){
    vector<int> lines;
    ifstream in;
    in.open("AdventOfCode1.1.txt");
    string line;
    int count = 0;
    while (getline(in, line)){
        lines.push_back(stoi(line));
        count++;
    }
    cout << get_num(lines, count) << endl;
    return 0;
}