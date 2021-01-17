#include <vector>
#include <iostream>

using namespace std;

enum type{
    occupied,
    empty,
    floor,
};

class Cell{
    private:
        type seatType;
    public:
        Cell(char t);
        type getSeatType();
        void setType(type t);
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
};