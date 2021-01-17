#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int countYeses(string group){
    stringstream ss(group);
    string line;
    int count = 0, index;
    string str = "";
    while (getline(ss, line, ' ')){
        for (int i = 0; i < line.length(); i++){
            char c = line[i];
            index = str.find(line[i]);
            if (index == -1){
                count += 1;
                str.push_back(c);
            }
        }
        
    }
    return count;
}

int main(){

    vector<string> groups;
    
    string answers;

    ifstream in;
    in.open("AdventOfCode6.txt");
    string read;

    while (getline(in, read)){
        if (read == ""){
            groups.push_back(answers);
            answers = "";
        } else {
            answers.append(" " + read);
        }
    }
    groups.push_back(answers);


    int sum = 0;
    for (int i = 0; i < groups.size(); i++){
        sum += countYeses(groups[i]);
    }
    
    cout << sum << endl;
    return 0;
}