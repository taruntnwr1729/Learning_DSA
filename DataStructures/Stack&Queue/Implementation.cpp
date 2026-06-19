#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*------QUEUE------*/
class QImpl{
    int start = 0;
    int Q[10];
    public:
    int end = -1;
    void push(int x){
        if ( end >= 9 ){
            cout<<"Overflow"<<endl;
        }else{
            end = end + 1;
            Q[end] = x;
        }
    }

    int topfun(){
        if (end == -1){
            cout<<"Queue is empty";
            return -1;
        }else{
            return Q[start];
        }
    }

    void pop(){
        if (end == -1){
            cout<<"Queue is empty";
        }else{
            
            start = start + 1;
        }

    }

};

/*------STACK------*/

class stImpl{
    int top = -1;
    int stack[10];

    public:

    void push(int x){
        
        if (top>=9){
            cout<<"Overflow"<<endl; 
        }else{
        top = top + 1;
        stack[top] = x;
    }


    }
    int topfun(){
        if (top == -1){
            cout<<"Stack is empty";

            return -1;
    }else{ 
        return stack[top];
    }
}

    void pop(){
        if (top == -1){
            cout<<"Stack is empty"<<endl;
        }else{
            top = top - 1;
        }
    }
};

/*-----STACK USING LINKED LIST-----*/
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


class StackLL{

    Node* top;
    int size = 0;

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size = size + 1;
        
    }
    void pop(){
        Node* temp = top;
        top = top->next;
        delete temp;
        size = size - 1;
    }

    int top(){
        Node* temp = top;
        return temp->data;
    }

};

/*-----QUEUE USING LINKED LIST-------*/
class QueueLL{
    Node* start;
    Node* end;
    int size = 0;

    void push(int x){
        Node* temp = new Node(x);

        if(start == NULL){
            start = end = temp;
        }else{
            end->next = temp;
            size = size + 1;
        }
    }
    void pop(){
        Node* temp;
        if(start == NULL){
            start = end = temp;

    }else{
        temp = start;
        start = start->next;
        delete temp;
        size = size - 1;
    }
}

    int top(){
        if(start == NULL){
            return -1; 
        }
        Node* temp;
        temp = start;
        return temp->data;
    }
};

int main(){

    stImpl s;
    QImpl s1;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    cout << "Top element: " << s.topfun() << endl;
    s.pop();
    cout << "Top element: " << s.topfun() << endl; 


    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    cout << "Top element: " << s1.topfun() << endl;
    s1.pop();
    cout << "Top element: " << s1.topfun() << endl; 


    return 0;
}