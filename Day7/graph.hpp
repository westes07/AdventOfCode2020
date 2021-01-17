#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

struct Bag;

struct heldBag{
    Bag *b;
    int number;
};

struct Bag{
    string color;
    vector<heldBag> contents;
    bool visited;
    int distance;
};

class BagTree {
    public:
        vector<Bag*> graph;
        void addBag(string c);
        void addConnection(string from, string to, int number);
        Bag* find(string color);
        void resetVisited();
        int countContents(string start);
};