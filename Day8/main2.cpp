#include "stack2.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream in;
    in.open("AdventOfCode8.txt");
    Stack stack;
    string line;

    while (getline(in, line)){
        stack.addArg(line);
    }
    stack.buildProgression();
    node* last = stack.progression.findNext(stack.progression.tail);
    int counter = 0;
    while (true){
        switch (last->arg->type){
            case no_op:
                last->arg->type = jmp;
                break;
            case jmp:
                last->arg->type = no_op;
                break;
            default:
                cout << "ERR" << endl;
                break;
        }
        if (stack.executeStack()){
            break;
        } else {
            switch (last->arg->type){
                case no_op:
                    last->arg->type = jmp;
                    break;
                case jmp:
                    last->arg->type = no_op;
                    break;
                default:
                    cout << "ERR" << endl;
                    break;
            }
            last = stack.progression.findNext(last);
        }
    }
    cout << stack.accumulator << endl;
    
    return 0;
}