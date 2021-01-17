#include "list.hpp"

List::List(){
    oneJolt = 0;
    threeJolt = 0;
    device = 3;
}

vector<int> List::getList(){
    return list;
}

int List::getMax(){
    return max;
}

bool List::checkMax(){
    bool changed = false;
    for (int i = 0; i < list.size(); i++){
        if (list[i] > max){
            changed = true;
            max = list[i];
        } 
    }
    return changed;
}

int List::find(int last, int difference){
    for (int i = 0; i < list.size(); i++){
        if(list[i] == last + difference){
            return i;
        }
    }
    return -1;
}

int List::findNext(int last){
    for (int i = 1; i < 4; i++){
        if (find(last, i) != -1){
            if (i == 1){
                oneJolt++;
            }else if (i == 3){
                threeJolt++;
            }
            int found = list[find(last, i)];
            sorted.push_back(found);
            return found;
        }
    }  
    return -1;
}

void List::addAdapter(int adapter){
    list.push_back(adapter);
    if(checkMax()){
        device = max+3;
    }
}

void List::runList(){
    int curr = 0;
    while (curr != max){
        curr = findNext(curr);
        if (curr == -1){
            cout << "ERR" << endl;
            break;
        }
    }
    threeJolt++;
    int result = oneJolt * threeJolt;
    cout << "One Jolt difference * Three Jolt difference = " << result << endl;
}