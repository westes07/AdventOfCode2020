#include <fstream>
#include <iostream>
#include "list.hpp"

using namespace std;

int max(vector<long long> list){
    long long max = list[0];
    for (int i = 1; i < list.size(); i++){
        if (list[i] > max){
            max = list[i];
        }
        
    }
    return max;
}

int min(vector<long long> list){
    long long min = list[0];
    for (int i = 1; i < list.size(); i++){
        if (list[i] < min){
            min = list[i];
        }
        
    }
    return min;
}

int main(){
    ifstream in;
    in.open("AdventOfCode9.txt");
    List numbers;
    vector<long long> list;
    string line;
    int count = 0;
    while (getline(in, line)){
        numbers.addNum(stoll(line));
        count++;
    }

    for (int i = 25; i < count; i++) {
        if (!numbers.checkIndex(i)){
            list = numbers.findSum(numbers.at(i));
            break;
        }
    }
    
    cout << min(list) + max(list) << endl;

    return 0;
}