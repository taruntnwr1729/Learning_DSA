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

Node* OddEvenLL(Node* head){
    if (head == NULL || head->next == NULL){
        return NULL;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even!=NULL && even->next !=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;

}

int main(){
    return 0;
}