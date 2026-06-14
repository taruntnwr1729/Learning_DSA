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
        Node* next = NULL;
        Node* back = NULL;

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

Node* DeleteHead(Node* head){
    if (head == NULL || head->next == NULL){
        delete head;
        return NULL;
    }
    Node* prev = head;
    head = prev->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
    
}

Node* deleteTail(Node* head){
    if (head == NULL || head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head ;
    Node* prev;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    
    delete temp;
    return head;
}

Node* removeK(Node* head, int k){
    if (head==NULL){
        return NULL;
    }
    int count = 0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if (count==k){
            break;
        
        }
        temp= temp->next;
    }
    if (temp==nullptr){
        return head;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;

    }else if(prev==NULL){

        DeleteHead(head);

    }else if(front == NULL){

        deleteTail(head);
    }else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
    }

    return head;


}

Node* InsertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val);

    newNode->next = head;
    newNode->back = nullptr;
    head->back = newNode;
    head = newNode;
    
    return head;
}

Node* InsertBeforeTail(Node* head, int val){
    Node* temp = head;
    Node* newNode = new Node(val);

    if(head->next == NULL){
        return InsertBeforeHead(head, val);
    }
    while(temp->next !=NULL){
        temp= temp->next;
        
    }

    Node* tail = temp; 
    Node* prev = tail->back;
    

    newNode->next = tail;
    newNode->back = prev;
    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* InsertBeforeK(Node* head, int k, int val){
    Node* temp = head;
    Node* newNode = new Node(val);
    int count = 0;

    while(temp !=NULL){

        if(k==1){
            return InsertBeforeHead(head,val);
        }
        if (count == k){
            break;
        }
        temp = temp->next;
        count++;
    }

        Node* prev = temp->back;
        newNode->next = temp;
        newNode->back = prev;
        prev->next = newNode;
        temp->back = newNode;
    
    return head;

}

void InsertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val);
    newNode->next = node;
    newNode->back = prev;
    prev->next = newNode;
    node->back = newNode;

    
}

int main(){
    vector <int> arr = {2,3,4,5,1,6,7};
    Node* head = convertArr2DLL(arr);
    InsertBeforeNode(head->next,100);
    InsertBeforeTail(head,3);
    printForward(head);
    

    return 0;
}