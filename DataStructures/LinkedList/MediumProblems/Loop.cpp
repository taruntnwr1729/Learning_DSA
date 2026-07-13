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

bool DetectLoop(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast !=NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next; 
        if(slow == fast){
            return true;
        }
    }

    return false;
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
    // --- CASE 1: Linear Linked List (No Loop) ---
    // 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    // Call DetectLoop and print the result
    if (DetectLoop(head)) {
        cout << "Is there any loop? : Yes" << endl;
    } else {
        cout << "Is there any loop? : No" << endl;
    }

    // --- CASE 2: Creating a Loop ---
    // Let's connect the last node (40) back to the second node (20)
    // 10 -> 20 -> 30 -> 40 
    //       ^           |
    //       |___________|
    head->next->next->next->next = head->next; 

    cout << "\nAfter creating a cycle..." << endl;
    
    // Note: We cannot call printList(head) here anymore because 
    // it would result in an infinite loop!
    
    if (DetectLoop(head)) {
        cout << "Is there any loop? : Yes" << endl;
    } else {
        cout << "Is there any loop? : No" << endl;
    }

    // --- Clean up memory ---
    // Because Case 2 has a loop, we break the loop first so we can safely delete the memory
    head->next->next->next->next = NULL; 
    
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
