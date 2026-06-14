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
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

Node* ConvertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//THIS IS A FUNCTION TO DELETE THE Nth NODE FROM LAST
Node* DeleteNLast(Node* head , int n){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    Node* fast = head;
    for(int i = 0; i<n; i++){
        fast = fast->next;
    }
    Node* slow = head;
    

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;

    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);


    return head;

}




int main(){

    vector <int> arr = {2,3,4,5,1,6,7};
    Node* head = ConvertArr2LL(arr);
    int n = 2;
    
    print(head);
    return 0;
}


