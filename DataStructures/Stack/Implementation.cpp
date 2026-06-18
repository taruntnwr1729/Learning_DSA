#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class stImpl{
    int top = -1;
    int stack[10];

    public:

    void push(int x){
        
        if (top>=10){
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

int main(){

    stImpl s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    cout << "Top element: " << s.topfun() << endl;
    s.pop();
    
    
    cout << "Top element: " << s.topfun() << endl; // Should print 10



    return 0;
}