#include "stack2.hpp"
#include <iostream>

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
    
    sign = contents[4];
    num = stoi(contents.substr(5));
    if (sign == '-'){
        num = 0 - num;
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

progressionList::progressionList(){
    head = NULL;
    tail = NULL;
}

progressionList::~progressionList(){
    node* crawler = tail;
    node* temp = tail;
    while (crawler != head){
        temp = crawler->prev;
        delete crawler;
        crawler = temp;
    }
}

node* progressionList::findNode(argument *arg){
    if(head == NULL || tail == NULL){
        return NULL;
    }
    node* front = head;
    node* back = tail;
    while (front != back && front != tail && back != head){
        if (front->arg == arg){
            return front;
        }
        if (back->arg == arg){
            return back;
        }
        front = front->next;
        back = back->prev;
    }
    return NULL;
}

void progressionList::addNode(argument *arg){
    node* newNode = new node;
    newNode->arg = arg;
    newNode->next = NULL;
    if (head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void progressionList::removeNode(argument *arg){
    node* toRemove = findNode(arg);
    if (toRemove == NULL){
        return;
    }
    if (head == NULL){
        return;
    }
    if (toRemove == head){
        head = toRemove->next;
        delete toRemove;
        return;
    }
    if (toRemove == tail){
        tail = toRemove->prev;
        delete toRemove;
        return;
    }
    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;
    delete toRemove;
}

node* progressionList::findNext(node* last){
    node * crawler = last->prev;
    while(crawler != head){
        if(crawler->arg->type == no_op || crawler->arg->type == jmp){
            return crawler;
        }
        crawler = crawler->prev;
    }
    return NULL;
}

Stack::Stack(){
    currIndex = 0;
}

void Stack::addArg(string arg){
    contents.push_back(argument(arg));
}

void Stack::setVisited(){
    for (int i = 0; i < contents.size(); i++){
        contents[i].visited = false;
    }
    
}

void Stack::buildProgression(){
    int index = 0;
    while(index != -1 && index <= contents.size()){
        progression.addNode(&contents[index]);
        index = contents[index].execute(index, accumulator);
    }
    accumulator = 0;
    setVisited();
}

bool Stack::executeStack(){
    setVisited();
    accumulator = 0;
    int index = 0;
    while(index != -1 && index <= contents.size()){
        index = contents[index].execute(index, accumulator);
    }
    return (index != -1);
}