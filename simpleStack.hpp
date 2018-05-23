#pragma once

#include <iostream>

struct stackItem {
    int data;
    stackItem * next;
};

void pushToStack(stackItem * &s, int x){
    if(!s)
        s = new stackItem{x, 0};
    else{
        stackItem * tmp = new stackItem{x , s};
        s = tmp;
    }
}

int popFromStack(stackItem * &s){
    if(s){
        int value = s->data;
        stackItem * tmp = s;
        s = s->next;
        delete tmp;
        tmp = 0;
        return value;
    }else{
        std::cout<<"Stos jest pusty!";
        return 0;
    }
}
