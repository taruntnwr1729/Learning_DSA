#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* Intersection(Node* firstHead, Node* secondHead){
    if(firstHead == NULL || secondHead == NULL){
        return NULL;

    }

    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2){
            return temp1;
        }
        if(temp1==NULL){
            temp1 = secondHead;
        }
        if(temp2 == NULL){
            temp2 = firstHead;

        }
    }
    return temp1;
}