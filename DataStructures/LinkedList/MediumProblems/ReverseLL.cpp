#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
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

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // 1. Create the nodes for the list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // 2. Print original list
    cout << "Original List: ";
    printList(head);

    // 3. Reverse the list
    head = ReverseLL(head);

    // 4. Print reversed list
    cout << "Reversed List: ";
    printList(head);

    // 5. Clean up memory (Good practice!)
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}