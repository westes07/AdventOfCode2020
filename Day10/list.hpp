#include <vector>
#include <iostream>
using namespace std;

class List{
    private:
        vector<int> list;
        int oneJolt;
        int threeJolt;
        int max;
        int device;
    public:
        vector<int> sorted;
        List();
        vector<int> getList();
        int getMax();
        bool checkMax();
        int find(int last, int difference);
        int findNext(int last);
        void addAdapter(int adapter);
        void runList();
};
