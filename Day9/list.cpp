#include "list.hpp"

void List::addNum(long long n){
    list.push_back(n);
}

bool List::checkIndex(int i){
    int preamble;
    if(i < 25){
        cout << "Index too low" << endl;
        return false;
    }
    preamble = i-25;
    for (int j = preamble; j < i; j++){
        for (int k = preamble; k < i; k++){
            if (k != j){
                if (list[k] + list[j] == list[i]){
                    return true;
                }
            }
        }
    }
    return false;
}

long long List::at(int i){
    cout << list[i] <<endl;
    return list[i];
}

vector<long long> List::findSum(long long target){
    vector<long long> retList;
    long long sum = 0;
    int start = 0, end = 1;
    while(sum != target){
        retList.clear();
        retList.push_back(list[start]);
        sum = list[start];
        while (sum < target){
            sum += list[end];
            retList.push_back(list[end]);
            end++;
        }
        start++;
        end = start+1;
    }
    return retList;
}