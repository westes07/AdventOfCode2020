#include "graph.hpp"

graph::graph(){
    adapter* outlet = new adapter;
    outlet->rating = 0;
    contents.push_back(outlet);
    device = 3;
}

graph::graph(List list){
    adapter* outlet = new adapter;
    outlet->rating = 0;
    contents.push_back(outlet);
    device = 3;
    for (int i = 0; i < list.sorted.size(); i++){
        adapter* newAdapter = new adapter;
        newAdapter->rating = list.sorted[i];
        contents.push_back(newAdapter);
    }
}

int graph::findMax(){
    int max = contents[0]->rating;
    for (int i = 0; i < contents.size(); i++){
        if(contents[i]->rating > max){
            max = contents[i]->rating;
        }
    }
    return max;
}

void graph::addAdapter(int rating){
    adapter* newAdapter = new adapter;
    newAdapter->rating = rating;
    contents.push_back(newAdapter);
}

adapter* graph::findAdapter(int search){
    for (int i = 0; i < contents.size(); i++){
        if (contents[i]->rating == search){
            return contents[i];
        }
    }
    return NULL;
}

void graph::createConnections(){
    int max = findMax();
    device = max+3;
    addAdapter(device);
    
    for (int i = 0; i < contents.size(); i++){
        for (int j = 1; j <= 3; j++){
            connection newConnection;
            newConnection.ada = findAdapter(contents[i]->rating-j);
            if (newConnection.ada != NULL){
                contents[i]->connected.push_back(newConnection);
            }
        }
    }
    
}


long long graph::traverse(){
    adapter* curr;
    long long sum;
    for (int i = 1; i < contents.size(); i++){
        sum = 0;
        curr = contents[i];
        for (int j = 0; j < curr->connected.size(); j++){
            sum += curr->connected[j].ada->distance;
        }
        cout << curr->rating << ":" << sum << endl;
        curr->distance = sum;
    }
    adapter* ret = findAdapter(device);
    if (ret != NULL){
        return ret->distance;
    } else {
        cout << "ERR" << endl;
        return -1;
    }
    
}