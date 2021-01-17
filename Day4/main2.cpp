#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

bool checkField(string name, string value){
    if(name == "byr"){
        return (stoi(value) >= 1920 && stoi(value) <= 2002);
    }
    if (name == "iyr"){
        return (stoi(value) >= 2010 && stoi(value) <= 2020);
    }
    if (name == "eyr"){
        return (stoi(value) >= 2020 && stoi(value) <= 2030);
    }
    if (name == "hgt"){
        int index = value.find('c');
        if (index != -1){
            return (stoi(value.substr(0, index)) >= 150 && stoi(value.substr(0, index)) <= 193);
        }
        index = value.find('i');
        if (index != -1){
            return (stoi(value.substr(0, index)) >= 59 && stoi(value.substr(0, index)) <= 76);
        }
        return false;
    }
    if (name == "hcl"){
        if (!(value[0] == '#' || value.length() == 7)){
            return false;
        }

        for (int i = 1; i < value.length(); i++){
            if (!(value[i] == '0' || value[i] == '1' || value[i] == '2' || value[i] == '3' || value[i] == '4' || value[i] == '5' || value[i] == '6' || value[i] == '7' || value[i] == '8' || value[i] == '9' || value[i] == 'a' || value[i] == 'b' || value[i] == 'c' || value[i] == 'd' || value[i] == 'e' || value[i] == 'f')){
                return false;
            }
            
        }
        
    }
    if (name == "ecl"){
        if (value == "amb"){
            return true;
        }
        if (value == "blu"){
            return true;
        }
        if (value == "brn"){
            return true;
        }
        if (value == "gry"){
            return true;
        }
        if (value == "grn"){
            return true;
        }
        if (value == "hzl"){
            return true;
        }
        if (value == "oth"){
            return true;
        }
        return false;
    }
    if (name == "pid"){
        return (value.length() == 9);
    }
    
    return true;
}

int countValid(vector<string> list){
    int count = 0;
    vector<string> passport;
    int fields;
    bool fieldsValid = true;

    for (int j = 0; j < list.size(); j++){
        string s = list[j];
        fields = 0;
        stringstream strst(s);
        string field;

        while (getline(strst, field, ' ')){
            int index = field.find(':');
            if (index != -1){
                fields++;
                fieldsValid = checkField(field.substr(0, index), field.substr(index+1));
                if (!fieldsValid){
                    break;
                }
                
            }
            
        }
        
        if (fieldsValid){
            if (fields == 8){
                count++;
            }
            if (fields == 7){
                if(s.find("cid") == -1){
                    count++;
                }
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