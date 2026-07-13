#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data= val;
        next = NULL;

    }
};

Node* ReverseLL(Node* head){

    if(head == NULL){
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;
    Node* front;
    
    while(temp!=NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;

    }

    return prev;
}


bool Palindrome(Node* head){

    if (head == NULL && head->next == NULL){
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = ReverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;

    while (second != NULL){
        if(first->data != second->data){
            ReverseLL(newHead);
            return false;
        }
        first->next;
        second->next;
    }
    ReverseLL(newHead);
    return true;
 

}

int main(){



    return 0;
}