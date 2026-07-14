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

Node* DeleteMiddle(Node* head){
    if( head == NULL || head->next == NULL){
       return NULL; 
    }
    Node* slow = head;
    Node* fast = head;

    fast = fast->next->next;

    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;

        fast = fast->next->next;

    }

    Node* middle = slow->next;
    slow->next = slow->next->next;
    free(middle);
    

    return head;

}