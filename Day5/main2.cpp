#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int getSeatID(string seat){
    int row, col;
    int max = 127;
    int min = 0;
    int buffer = 128;
    for (int i = 0; i < 7; i++){
        buffer = buffer/2;
        if (seat[i] == 'F'){
            max -= buffer;
        } else if(seat[i] == 'B'){
            min += buffer;
        }
    }
    row = max;
    max = 7;
    min = 0;
    buffer = 8;
    for (int i = 7; i < 10; i++){
        buffer = buffer/2;
        if (seat[i] == 'L'){
            max -= buffer;
        } else if(seat[i] == 'R'){
            min += buffer;
        }
    }
    col = max;

    return ((row * 8) + col);
}

int main(){
    vector<string> seats;
    

    ifstream in;
    in.open("AdventOfCode5.txt");
    string read;

    while (getline(in, read)){
        seats.push_back(read);
    }
    
    bitset<805> bits;
    for (int i = 0; i < seats.size(); i++){
        bits[getSeatID(seats[i])] = 1;
    }

    for (int i = 1; i < bits.size() - 1; i++){
        if (bits.test(i) == 0){
            if (bits.test(i-1) == 1 && bits.test(i+1) == 1){
                cout << i;
            }
        }
    }
    return 0;
}