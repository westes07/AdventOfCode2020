#include "grid.hpp"

Ferry::Ferry(){
    rows = 0;
    cols = 0;
}

void Ferry::readLine(string line){
    cols = line.size();
    for (int i = 0; i < line.size(); i++){
        Cell cell;
        switch (line[i]){
            case 'L':
                cell = empty;
                break;
            
            case '.':
                cell = Cell::floor;
                break;
            case '#':
                cell = occupied;
                break;
            default:
                cout << "ERR" << endl;
                return;
        }
        grid.push_back(cell);
    }
    rows++;
}

int Ferry::countOccupied(){
    int count = 0;
    for (int i = 0; i < grid.size(); i++){
        if (grid[i] == occupied){
            count++;
        } 
    }
    return count;
}

int Ferry::getIndex(int row, int col){
    return (row*cols) + col;
}

bool Ferry::findFirstSeat(int dRow, int dCol, int row, int col){
    Cell ret;
    int i = row+dRow;
    int j = col+dCol;
    // cout << "start find" << endl;
    while((i < rows && j < cols) && (i >= 0 && j >= 0)){
        
        ret = grid[getIndex(i, j)];
        if(ret == occupied){
            return true;
        }
        if(ret == empty){
            return false;
        }
        j += dCol;
        i += dRow;
    }
    return false;
}

int Ferry::countNeighbors(int row, int col){
    int count = 0;
    int firstSeatRow, firstSeatCol;
    if(findFirstSeat(0, -1, row, col)){count++;}
    if(findFirstSeat(0, 1, row, col)){count++;}
    if(findFirstSeat(1, 0, row, col)){count++;}
    if(findFirstSeat(1, -1, row, col)){count++;}
    if(findFirstSeat(-1, 0, row, col)){count++;}
    if(findFirstSeat(-1, -1, row, col)){count++;}
    if(findFirstSeat(1, 1, row, col)){count++;}
    if(findFirstSeat(-1, 1, row, col)){count++;}
    return count;
}

bool Ferry::tick(){
    bool changed = false;
    vector<Cell> next;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int index = getIndex(i, j);
            Cell seat = grid[index];

            Cell nextCell;
            int occupiedNeighbors = countNeighbors(i, j);
            cout << occupiedNeighbors << " ";
            switch(seat) {
                case empty:
                    if(occupiedNeighbors == 0){
                        nextCell = occupied;
                        changed = true;
                    } else {
                        nextCell = empty;
                    }
                    break;
                case occupied:
                    if(occupiedNeighbors >= 5){
                        nextCell = empty;
                        changed = true;
                    } else {
                        nextCell = occupied;
                    }
                    break;
                case Cell::floor:
                    nextCell = Cell::floor;
                    break;
            }
            next.push_back(nextCell);
        }
        cout << endl;
    }
    if(changed){
        for (int i = 0; i < next.size(); i++){
            grid[i] = next[i];
        }
    }
    return changed;
}

void Ferry::printGrid(){
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            switch(grid[getIndex(i, j)]){
                case occupied:
                    cout << "#";
                    break;
                case empty:
                    cout << "L";
                    break;
                case Cell::floor:
                    cout << ".";
                    break;
            }
        }
        cout << endl;
    }
}