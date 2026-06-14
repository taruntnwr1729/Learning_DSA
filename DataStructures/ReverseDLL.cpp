#include <iostream>
#include <vector>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data= data1;
        next = next1;
        back = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        Node* next = nullptr;
        Node* back = nullptr;

    }

};


void printForward(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}
void printBackward(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->back;
    }
    cout<<endl;
}

Node* convertArr2DLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }


    return head;

}

/*------------------------------------------------------------*/

Node* ReverseDLL(Node* head){

    if (head == nullptr || head->next == nullptr ){
        return head;
    }
    Node* tempprev = NULL;
    Node* current = head;

    while(current != nullptr){
        tempprev = current->back;
        current->back = current ->next;
        current->next = tempprev;

        current = current->back;
    }

    return tempprev->back;
}





int main(){

    vector <int> arr = {2,3,4,5,1,6,7};
    Node* head = convertArr2DLL(arr);
    head = ReverseDLL(head);
    printForward(head);

    return 0;
}