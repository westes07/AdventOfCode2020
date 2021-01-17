#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int countValid(vector<string> list){
    int count = 0;
    vector<string> passport;
    int fields;

    for (int j = 0; j < list.size(); j++){
        string s = list[j];
        fields = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ':'){
                fields++;
            }
        }
        
        if (fields == 8){
            count++;
        }
        if (fields == 7){
            if(s.find("cid") == -1){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<string > passports;

    ifstream in;
    in.open("AdventOfCodeDay4.txt");
    string read;
    string line;
    bool isBlank;

    while (getline(in, read)){
        if (read == ""){
            passports.push_back(line);
            line = "";
        } else {
            line.append(" " + read);
        }
    }
    passports.push_back(line);
    cout << countValid(passports) << endl;

    return 0;
}