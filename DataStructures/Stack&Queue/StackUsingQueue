#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class StackUsingQueues{
    private:
    queue <int> q1;
    queue <int> q2;

    public:

    void push(int x){
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);

    }

    void pop(){
        if(q1.empty()){
            cout<<"Stack Underflow"<<endl;
            return ;
        }
        q1.pop();
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }else{
            return q1.front();
        }
    }

    int size(){
        if(q1.empty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }else{
            return q1.size();
        }
    }

};

int main(){

    StackUsingQueues st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; 

    st.pop();
    cout << "Top element after pop: " << st.top() << endl; 

    cout << "Stack size: " << st.size() << endl; 

    return 0;
}
