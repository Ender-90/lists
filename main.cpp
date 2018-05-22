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
        tmp = 0;
        tmp = oneList;
        while(tmp && tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new ele{x, 0};
    }
}

void displayList(ele * oneList){
    ele * tmp = 0;
    tmp = oneList;

    cout<<"\n";
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
}

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

void insertToList(int x, int i, ele * &oneList);

void removeFromList(int i, ele * &oneList);
int read(int i, ele * oneList);


int main()
{
    ele * testOneList;
    testOneList = 0;
    constructNewList(testOneList);

//    ele * searchElement = searchInList(9 , testOneList);
//    cout<<"\n"<<searchElement->data;

    return 0;
}
