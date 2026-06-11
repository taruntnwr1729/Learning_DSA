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

int lengthcheckfun(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp != nullptr){
    
        temp = temp->next;
        count++;
    }
    return count;

}
int Search(Node* head, int val){
    int found = 0;
    Node* temp = head;
    while (temp != nullptr){
        if(temp->data == val){
            return 1;
        }else{
            temp = temp->next;
            
        }   
        }
    return 0;

}
Node* DeleteHeadFun(Node* head){

    if (head == NULL){
        return head;

    }else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return head;
}



Node* RemoveLast(Node* head){
    
    if (head == NULL || head->next == NULL){
        return NULL;
    }
    
    Node* temp = head;
    while(temp->next->next != NULL){
            temp = temp->next;
        }
        
        temp->next= NULL;    
    
    return head;

    }

Node* RemoveK(Node* head, int k){
    if(head==NULL)return head;
    if(k==1){
        Node* temp = head;
        head= head->next;
        delete(temp);
        return head;
    }
    int count=0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp !=NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp= temp->next;
    }
    return head;
}

Node* InsertHead(Node* head, int val){
    Node* temp;
    temp->data=val;
    temp->next = head;
    head = temp;

    return head;
}

Node* InsertLast(Node* head, int val){
    if (head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;

    }

    Node* newNode = new Node(val);
    temp ->next = newNode;
    newNode->next = NULL;
    return head;

    }

int main(){

    vector <int> arr = {2,3,4,5,1,6,7};
    Node* head = ConvertArr2LL(arr);
    head = InsertLast(head,5);
    print(head);
    return 0;
}