#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int val){
        data = val;
        next = NULL;
    }


};

int MiddleofLL(Node* head){
    if(head == NULL){
        return -1;
    }

    Node* forward = head; //Hare
    Node* backward = head; //Tortoise

    while(forward!=NULL && forward->next !=NULL){
        forward = forward->next->next;
        backward = backward->next;

    }
    
    return backward->data;
}

int main(){

     

    return 0;
}