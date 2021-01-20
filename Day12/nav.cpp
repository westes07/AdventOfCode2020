#include "nav.hpp"

Compass::Compass(){
    bearing = 90;
    dir = east;
}

void Compass::changeBy(int degrees){
    bearing += degrees;
    if(bearing >= 360){
        bearing -= 360;
    }
    if(bearing < 0){
        bearing = 360 + bearing;
    }
    calcDir();
}

void Compass::calcDir(){
    if(bearing < 90){
        dir = north;
    } else if (bearing < 180){
        dir = east;
    } else if (bearing < 270){
        dir = south;
    } else if (bearing < 360){
        dir = west;
    }
}

direction Compass::getDirection(){
    return dir;
}

Nav::Nav(){
    xCoord = 0;
    yCoord = 0;
}

void Nav::executeArg(arg command){
    
    switch(command.type){
        case 'N':
            yCoord += command.magnitude;
            break;
        case 'E':
            xCoord += command.magnitude;
            break;
        case 'S':
            yCoord -= command.magnitude;
            break;
        case 'W':
            xCoord -= command.magnitude;
            break;
        case 'L':
            bearing.changeBy(-1*command.magnitude);
            break;
        case 'R':
            bearing.changeBy(command.magnitude);
            break;
        case 'F':
            switch(bearing.getDirection()){
                case north:
                    yCoord += command.magnitude;
                    break;
                case east:
                    xCoord += command.magnitude;
                    break;
                case south:
                    yCoord -= command.magnitude;
                    break;
                case west:
                    xCoord -= command.magnitude;
                    break;
            }
            break;
    }
    cout << "\n" << command.type << command.magnitude << endl;
    cout << xCoord << ", " << yCoord << endl;
}

int Nav::manhattanDistance(){
    cout << xCoord << ", " << yCoord << endl;
    return (abs(xCoord) + abs(yCoord));
}