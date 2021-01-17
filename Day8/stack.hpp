#include <string>
#include <vector>

using namespace std;


enum argType{
    acc,
    no_op,
    jmp,
};

class argument {
    private:
        bool visited;
        argType type;
        int num;
    public:
        argument(string contents);
        //Returns the new index
        int execute(int currIndex, int &accumulator);
};


class Stack{
    private:
        vector<argument> contents;
        int currIndex;
        int accumulator = 0;
     public:
        Stack();
        void addArg(string arg);
        int executeStack();
};

