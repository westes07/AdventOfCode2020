#include "graph.hpp"

void BagTree::addBag(string color){
    Bag *newBag = new Bag;
    newBag->color = color;
    newBag->visited = false;
    newBag->distance = 0;
    graph.push_back(newBag);
}

Bag* BagTree::find(string color) {
    for (int i = 0; i < graph.size(); i++){
        if(graph[i]->color == color){
            return graph[i];
        }
    }
    return NULL;
}

void BagTree::addConnection(string from, string to, int number){
    Bag* b1 = find(from);
    Bag* b2 = find(to);
    if (b1 == NULL){
        cout << "ERR: Connection failed" << endl;
        return;
    }
    if (b2 == NULL){
        addBag(to);
        b2 = find(to);
    }
    
    
    heldBag *hB = new heldBag;
    hB->b = b2;
    hB->number = number;
    b1->contents.push_back(*hB);
}

void BagTree::resetVisited(){
    for (int i = 0; i < graph.size(); i++){
        graph[i]->visited = false;
    }
    
}

int countHelper(Bag* bag){
    int count = 0;
    int ref = 0;
    if (bag->contents.size() == 0){
        return 0;
    }

    for (int i = 0; i < bag->contents.size(); i++){
        count += bag->contents[i].number * (1 + countHelper(bag->contents[i].b));
    }
    
    return count;
}

int BagTree::countContents(string start){
    Bag* root = find(start);
    return countHelper(root);
}