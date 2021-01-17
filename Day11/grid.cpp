#include "grid.hpp"

Cell::Cell(char t){
    switch (t){
        case 'L':
            seatType = type::empty;
            break;
        case '.':
            seatType = type::floor;
            break;
        case '#':
            seatType = type::occupied;
            break;
        default:
            cout << "ERR: cell creation" << endl;
            break;
    }
};

void Cell::setType(type t){
    seatType = t;
}

type Cell::getSeatType(){
    // switch (seatType){
    //     case occupied:
    //         cout << "occupied" << endl;
    //         break;
    //     case type::empty:
    //         cout << "empty" << endl;
    //         break;
    //     case type::floor:
    //         cout << "floor" << endl;
    //         break;
    // }
    return seatType;
}

Ferry::Ferry(){
    rows = 0;
    cols = 0;
}

void Ferry::readLine(string line){
    cols = line.size();
    for (int i = 0; i < line.size(); i++){
        Cell cell(line[i]);
        grid.push_back(cell);
    }
    rows++;
}

int Ferry::countOccupied(){
    int count = 0;
    for (int i = 0; i < grid.size(); i++){
        if (grid[i].getSeatType() == occupied){
            count++;
        } 
    }
    return count;
}

int Ferry::getIndex(int row, int col){
    return (row*cols) + col;
}

int Ferry::countNeighbors(int row, int col){
    int count = 0;
    if (row == 0){
        // cout << row << " zero" << endl;
        if(col == 0){
            if(grid[getIndex(row+1, col)].getSeatType() == type::occupied){count++;}
            if(grid[getIndex(row, col+1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row+1, col+1)].getSeatType() == occupied){count++;}
        } else if(col == cols-1){
            if(grid[getIndex(row+1, col)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col-1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row+1, col-1)].getSeatType() == occupied){count++;}
        } else {
            if(grid[getIndex(row+1, col)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col+1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row+1, col+1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col-1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row+1, col-1)].getSeatType() == occupied){count++;}
        }
    } else if (row == rows-1){
        if(col == 0){
            if(grid[getIndex(row-1, col)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col+1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row-1, col+1)].getSeatType() == occupied){count++;}
        } else if(col == cols){
            if(grid[getIndex(row-1, col)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col-1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row-1, col-1)].getSeatType() == occupied){count++;}
        } else {
            if(grid[getIndex(row-1, col)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col+1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row-1, col+1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row, col-1)].getSeatType() == occupied){count++;}
            if(grid[getIndex(row-1, col-1)].getSeatType() == occupied){count++;}
        }
    }else if(col == 0){
        if(grid[getIndex(row, col+1)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row+1, col)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row+1, col+1)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row-1, col)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row-1, col+1)].getSeatType() == occupied){count++;}
    }else if(col == cols-1){
        if(grid[getIndex(row, col-1)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row+1, col)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row+1, col-1)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row-1, col)].getSeatType() == occupied){count++;}
        if(grid[getIndex(row-1, col-1)].getSeatType() == occupied){count++;}
    } else {
        if(grid[getIndex(row, col-1)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row, col+1)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row+1, col)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row+1, col-1)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row-1, col)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row-1, col-1)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row+1, col+1)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
        if(grid[getIndex(row-1, col+1)].getSeatType() == occupied){
            count++;
            cout << row << " : " << col << " true" << endl;    
        }
    }
    // cout << count << " : ";
    return count;
}

bool Ferry::tick(){
    bool changed = false;
    vector<Cell> next;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int index = getIndex(i, j);
            Cell seat = grid[index];

            Cell nextCell('L');
            int occupiedNeighbors = countNeighbors(i, j);
            // cout << occupiedNeighbors << endl;
            type t = seat.getSeatType();
            // switch (t){
            //     case occupied:
            //         cout << "occupied : ";
            //         break;
            //     case type::empty:
            //         cout << "empty : ";
            //         break;
            //     case type::floor:
            //         cout << "floor : ";
            //         break;
            // }
            // cout << occupiedNeighbors << endl;
            if (t == type::empty){
                if(occupiedNeighbors == 0){
                    nextCell.setType(occupied);
                    changed = true;
                }
            }else if (t == type::occupied){
                cout << "Occupied" << endl;
                if (occupiedNeighbors >= 4){
                    nextCell.setType(type::empty);
                    changed = true;
                }                
            }else{
                nextCell.setType(seat.getSeatType());
            }
            next.push_back(nextCell);
        }
    }
    grid.clear();
    for (int i = 0; i < next.size(); i++){
        grid.push_back(next[i]);
    }
    return changed;
}