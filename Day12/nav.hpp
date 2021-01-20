#include <iostream>
#include <cmath>

using namespace std;

enum direction {
    north,
    south,
    east,
    west,
};

class Compass {
    private:
        int bearing;
        direction dir;
    public:
        Compass();
        void changeBy(int degrees);
        void calcDir();
        direction getDirection();
};

struct arg {
    char type;
    int magnitude;
};

class Nav {
    private:
        int xCoord;
        int yCoord;
        Compass bearing;
    public:
        Nav();
        void executeArg(arg command);
        int manhattanDistance();
};