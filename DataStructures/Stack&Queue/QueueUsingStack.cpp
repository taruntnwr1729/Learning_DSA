#include <iostream>
#include <stack>
#include <stdexcept>
#include <algorithm>
using namespace std;

class QueueUsingStack{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x){
        //this loop moves every element to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        //push the new element
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        if(s1.empty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }else{
            s1.pop();
        }

    }

    int front(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return s1.top();
        }
        
    }
};

int main(){
    QueueUsingStack q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Outputs 10 (FIFO)

    q.pop();
    cout << "Front element after pop: " << q.front() << endl;

    return 0;
}