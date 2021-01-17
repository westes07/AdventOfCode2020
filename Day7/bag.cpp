#include "bag.hpp"

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

void BagTree::addConnection(string from, string to){
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
    b1->contents.push_back(*hB);
}

void BagTree::resetVisited(){
    for (int i = 0; i < graph.size(); i++){
        graph[i]->visited = false;
    }
    
}

bool BagTree::traverseSearch(string root, string search){
    resetVisited();
    Bag* bagRoot = find(root);
    if (bagRoot == NULL){
        cout << "ERR: Traversal failed" << endl;
    }
    queue<Bag*> q;

    bagRoot->visited = true;

    q.push(bagRoot);
    Bag* crawler;
    while (!q.empty()){
        crawler = q.front();
        q.pop();
        if (crawler->color == search){
            return true;
        }
        
        crawler->visited = true;
        for (int i = 0; i < crawler->contents.size(); i++){
            if (!crawler->contents[i].b->visited){
                q.push(crawler->contents[i].b);
            }
        }
    }
    return false;
}

int BagTree::countRoots(string color){
    int count = 0;
    for (int i = 0; i < graph.size(); i++){
        if(traverseSearch(graph[i]->color, color)){
            count++;
        }
    }
    return count;
}