#include <iostream>

#include "simpleStack.hpp"

using namespace std;


// one-directional list

struct ele{
    int data;
    ele * next;
};

void addToEndOfList(int x, ele * &oneList){
    if(!oneList)
        oneList = new ele{x, 0};
    else{
        ele * tmp;
        tmp = oneList;
        while(tmp && tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new ele{x, 0};
    }
}

void displayList(ele * oneList);

void constructNewList(ele * &oneList){
    addToEndOfList(5, oneList);
    addToEndOfList(7, oneList);
    addToEndOfList(8, oneList);
    addToEndOfList(17, oneList);
    addToEndOfList(32, oneList);
    displayList(oneList);
    addToEndOfList(9, oneList);
    addToEndOfList(1, oneList);
    addToEndOfList(2, oneList);
    addToEndOfList(8, oneList);
    addToEndOfList(11, oneList);
    displayList(oneList);
}

// Ex. 01 - simple operations on one-directional lists

ele * searchInList(int x, ele * oneList){
    ele * tmp = oneList;
    bool isFound = false;

    while(tmp){
        if(tmp->data == x){
            isFound = true;
            break;
        }
        tmp = tmp->next;
    }

    if(isFound)
        return tmp;
    else
        return 0;
}

void insertToList(int x, int i, ele * &oneList){

    ele * actualItem = oneList;
    ele * lastItem = 0;
    int counter = 0;
    bool isFound = false;

    while(actualItem && !isFound){
        counter++;
        if(counter == i){
            isFound = true;
            break;
        }
        lastItem = actualItem;
        actualItem = actualItem->next;
    }

    if(isFound){
        ele * tmp = new ele{x, actualItem};
        lastItem->next = tmp;
    }else{
        cout<<"Podany element nie istnieje";
    }
}

void removeFromList(int i, ele * &oneList){

    ele * actualItem = oneList;
    ele * lastItem = 0;
    int counter = 0;
    bool isFound = false;

    while(actualItem && !isFound){
        counter++;
        if(counter == i){
            isFound = true;
            break;
        }
        lastItem = actualItem;
        actualItem = actualItem->next;
    }

    if(isFound){
        lastItem->next = actualItem->next;
        delete actualItem;
        actualItem = 0;
    }else{
        cout<<"Podany element nie istnieje";
    }
}

int read(int i, ele * oneList){

    ele * actualItem = oneList;
    int counter = 0;
    bool isFound = false;

    while(actualItem && !isFound){
        counter++;
        if(counter == i){
            isFound = true;
            break;
        }
        actualItem = actualItem->next;
    }

    if(isFound)
        return actualItem->data;
    else{
        cout<<"Podany element nie istnieje";
        return -1;
    }
}

// Ex. 02;

int sizeOfList(ele * oneList){
    int counter = 0;
    ele * tmp = oneList;
    while(tmp){
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

// Ex. 03

void displayList(ele * oneList){
    ele * tmp = oneList;

    cout<<"\n";
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<" Koniec listy";
}


// Ex. 04

void destroyList(ele * &oneList){
    ele * tmp = oneList;
    ele * next = 0;
    while(tmp){
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    oneList = 0;
}

// Ex. 05

ele * readAdress(int i, ele * oneList){

    ele * actualItem = oneList;
    int counter = 0;
    bool isFound = false;

    while(actualItem && !isFound){
        counter++;
        if(counter == i){
            isFound = true;
            break;
        }
        actualItem = actualItem->next;
    }

    if(isFound)
        return actualItem;
    else{
        cout<<"Podany element nie istnieje";
        return 0;
    }
}

// Ex. 06

void displayRevListWithStack(ele * oneList){

    ele * tmp = oneList;
    stackItem * s = 0;
    while(tmp){
        pushToStack(s, tmp->data);
        tmp = tmp->next;
    }
    cout<<"\n";

    while(s)
        cout<<popFromStack(s)<<" ";
}

// Ex. 07

void displayRevListWithoutStack(ele * oneList){
    int length = sizeOfList(oneList);
    ele * displayElements [length];

    ele * tmp = oneList;
    for(int i = 0; i < length; i++){
        if(tmp){
            displayElements[i] = tmp;
            tmp = tmp->next;
        }
    }

    cout<<"\n";

    for(int i = length - 1; i >= 0; i--){
        if(displayElements[i])
            cout<<displayElements[i]->data<<" ";
    }
}

// Ex. 08

ele * unionLists(ele* l1, ele * l2){
    if(!l1)
        return l2;
    else if(!l2)
        return l1;
    else{
        ele * unionList = 0;
        ele * tmp = l1;
        while(tmp){
            addToEndOfList(tmp->data, unionList);
            tmp = tmp->next;
        }
        tmp = l2;
        while(tmp){
            addToEndOfList(tmp->data, unionList);
            tmp = tmp->next;
        }
        return unionList;
    }
}

// Ex. 10

ele * findMinInList(ele * oneList){
    ele * tmp = oneList;

    if(tmp){
        ele * minElement = tmp;

        while(tmp){
            tmp = tmp->next;
            if(tmp && tmp->data < minElement->data)
                minElement = tmp;
        }
        return minElement;
    }else{
    cout<<"Lista jest pusta.";
    return 0;
    }
}


//=================================
int main()
{
    ele * testOneList = 0;
    constructNewList(testOneList);

    ele * searchElement = searchInList(9 , testOneList);
    if(searchElement)
        cout<<"\n"<<searchElement->data;

    insertToList(14, 3, testOneList);
    displayList(testOneList);

    removeFromList(3, testOneList);
    displayList(testOneList);

    cout<<"\n"<<read(3, testOneList);
    cout<<"\n"<<sizeOfList(testOneList);
    cout<<"\n"<<readAdress(3, testOneList);
    displayRevListWithStack(testOneList);
    displayRevListWithoutStack(testOneList);
    cout<<"\n"<<findMinInList(testOneList)->data;

    ele * testTwoList = unionLists(testOneList, testOneList);
    displayList(testTwoList);

    ele * testThreeList = unionLists(testOneList, 0);
    displayList(testThreeList);

//    destroyList(testOneList);
//    displayList(testOneList);

    return 0;
}
