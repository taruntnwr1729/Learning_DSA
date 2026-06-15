#include <iostream>
#include <vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
       data = data1;
       next = nullptr;
    }
    public:
    Node(int data1, Node* next1 ){
        data = data1;
        next = next1;
        }

};

Node* ConvertArr2LL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1 ; i < arr.size(); i++){
        Node* temp= new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printForward(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

Node* Add2LL(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry = 0;


    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if (temp1){
            sum = sum + temp1->data;
            } 
        if(temp2){ 
            sum = sum + temp2->data;
        }
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        current->next = newNode;
        current = newNode;

        if (temp1){ 
            temp1 = temp1->next;
        }
        if (temp2){
            temp2 = temp2->next;
        }
        
        }

        if (carry){
            Node* carryNode = new Node(carry);
            current ->next = carryNode;
        }
            

        return dummyNode->next;
    }


int main(){
    vector <int> arr1 = {1,5,4,3,6,7,2,3,9};
    vector <int> arr2 = {1,5,4,3,6,9};
    Node* head1 = ConvertArr2LL(arr1);
    Node* head2 = ConvertArr2LL(arr2);
    Node* newHead = Add2LL(head1, head2);
    printForward(newHead);

    return 0;
}  
