#include <vector>
#include <iostream>
#include <queue>
#include "list.hpp"
using namespace std;

struct adapter;

struct connection{
    adapter* ada;
};

struct adapter{
    int rating;
    vector<connection> connected;
    long long distance;
    adapter(){
        distance = 1;
    }
};

class graph {
    private:
        int device;
        vector<adapter*> contents;
    public:
        graph();
        graph(List list);
        int findMax();
        void createConnections();
        void addAdapter(int rating);
        void setVisited();
        adapter* findAdapter(int search);
        long long traverse();
};