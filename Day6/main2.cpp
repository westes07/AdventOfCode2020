#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int countYeses(string group){
    map<char, int> answerCount;
    stringstream ss(group);
    string line;
    int count = 0, groupSize = -1;
    while (getline(ss, line, ' ')){
        groupSize++;
        for (int i = 0; i < line.length(); i++){
            char c = line[i];
            if (answerCount.find(c) == answerCount.end()){
                answerCount.insert(std::pair<char, int>(c, 1));
            } else {
                answerCount.at(c) = answerCount.at(c) + 1;
            }
            
        }
        
    }
    
    
    map<char, int>::iterator itr = answerCount.begin();
    while (itr != answerCount.end()){
        cout << itr->second << " ";
        if (itr->second == groupSize){
            count++;
        }
        itr++;
    }
    
    cout << groupSize << endl;
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