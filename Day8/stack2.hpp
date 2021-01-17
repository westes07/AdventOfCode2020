#include <string>
#include <vector>

using namespace std;


enum argType{
    acc,
    no_op,
    jmp,
};

class argument {
    public:
        bool visited;
        int num;
        argType type;
        argument(string contents);
        //Returns the new index
        int execute(int currIndex, int &accumulator);
};


struct node{
    node *prev;
    argument *arg;
    node *next;
};

class progressionList{
    public:
        node *head;
        node *tail;
        progressionList();
        ~progressionList();
        node* findNode(argument *arg);
        void addNode(argument *arg);
        void removeNode(argument *arg);
        node* findNext(node* last);
};

class Stack{
    private:
        vector<argument> contents;
        int currIndex;
     public:
        progressionList progression;
        int accumulator = 0;
        Stack();
        void addArg(string arg);
        void buildProgression();
        void setVisited();
        bool executeStack();
        void tryAll();
};

