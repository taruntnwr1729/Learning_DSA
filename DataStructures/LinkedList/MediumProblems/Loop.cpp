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

    if(head == NULL){
        return false;
    }

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

Node* LoopStart(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow==fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;

            }
            return slow;

            
        }
    }
    return NULL;


}

int LoopLength(Node* head){
    if(head==NULL){
        return 0;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        int counter = 1;
        if(slow==fast){
            fast= fast->next;
            while(slow != fast){
                fast = fast->next;
                counter++;
                
            }
            return counter;
            
        }
        
        
    }
    return 0;

}

int main() {
    // --- CASE 1: Linear Linked List (No Loop) ---
    // 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next= new Node(60); 
    

    // Call DetectLoop and print the result
    if (DetectLoop(head)) {
        cout << "Is there any loop? : Yes" << endl;
    } else {
        cout << "Is there any loop? : No" << endl;
    }


    head->next->next->next->next->next->next = head->next; 

    cout << "\nAfter creating a cycle..." << endl;
    

    
    if (DetectLoop(head)) {
        cout << "Is there any loop? : Yes" << endl;
    } else {
        cout << "Is there any loop? : No" << endl;
    }
    
    Node* start = LoopStart(head);
    
    
    cout<<"Starting point of loop is: "<<start->data;


    return 0;
}
