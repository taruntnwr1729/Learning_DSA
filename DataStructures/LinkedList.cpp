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

int lengthcheckfun(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp != nullptr){
    
        temp = temp->next;
        count++;
    }
    return count;

}


int main(){

    vector <int> arr = {2,3,4,5,1,6,7};
    Node* head = ConvertArr2LL(arr);
    Node* temp = head;
    while (temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    cout<<lengthcheckfun(head);
    return 0;
}