#include <vector>
#include <iostream>

using namespace std;

enum Cell{
    occupied,
    empty,
    floor,
};

class Ferry{
    private:
        vector<Cell> grid;
        int rows;
        int cols;
    public:
        Ferry();
        void readLine(string line);
        bool tick();
        int getIndex(int row, int col);
        int countNeighbors(int row, int col);
        int countOccupied();
        void printGrid();
        bool findFirstSeat(int, int, int, int);
};