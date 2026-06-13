#include <iostream>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data = data1;
        Node* next = NULL;
        Node* prev = NULL;

    }
};

void printForward(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

void printBackword(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->prev;
    }
    cout<<endl;
}



int main(){


    return 0;
}