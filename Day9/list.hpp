#include <vector>
#include <iostream>
using namespace std;

class List{
    private:
        vector<long long> list;
    public:
        void addNum(long long n);
        bool checkIndex(int i);
        long long at(int i);
        vector<long long> findSum(long long target);
};
