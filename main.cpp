#include <iostream>

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
    displayList(oneList);
    addToEndOfList(9, oneList);
    addToEndOfList(8, oneList);
    addToEndOfList(11, oneList);
    displayList(oneList);
}

// Ex. 01 - simple operations on one-directional lists

ele * searchInList(int x, ele * oneList){
    ele * tmp = oneList;
    bool isFound = false;

    while(tmp && !isFound){
        tmp = tmp->next;
        if(tmp->data == x)
            isFound = true;
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

//=================================
int main()
{
    ele * testOneList = 0;
    constructNewList(testOneList);

    ele * searchElement = searchInList(9 , testOneList);
    cout<<"\n"<<searchElement->data;

    insertToList(14, 3, testOneList);
    displayList(testOneList);

    removeFromList(3, testOneList);
    displayList(testOneList);

    cout<<"\n"<<read(3, testOneList);
    cout<<"\n"<<sizeOfList(testOneList);
    cout<<"\n"<<readAdress(3, testOneList);
//    destroyList(testOneList);
//    displayList(testOneList);

    return 0;
}
