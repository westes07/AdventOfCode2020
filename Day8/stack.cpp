#include "stack.hpp"

argument::argument(string contents){
    string arg;
    char sign;
    arg = contents.substr(0, 3);
    num = 0;
    if (arg == "acc"){
        type = acc;
    } else if (arg == "nop") {
        type = no_op;
    } else if (arg == "jmp"){
        type = jmp;
    }
    
    if (type != no_op){
        sign = contents[4];
        num = stoi(contents.substr(5));
        if (sign == '-'){
            num = 0 - num;
        }
    }
}

int argument::execute(int currIndex, int &accumulator){
    int index = currIndex;
    if (visited){
        return -1;
    }
    
    switch (type){
        case no_op:
            index++;
            break;
        case acc:
            index++;
            accumulator += num;
            break;
        case jmp:
            index += num;
            break;
    }
    visited = true;
    return index;
}

Stack::Stack(){
    currIndex = 0;
}

void Stack::addArg(string arg){
    contents.push_back(argument(arg));
}

int Stack::executeStack(){
    int index = 0;
    while(index != -1 && index <= contents.size()){
        index = contents[index].execute(index, accumulator);
    }
    return accumulator;
}