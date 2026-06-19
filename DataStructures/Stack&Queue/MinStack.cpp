#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


class MinStackPairs{
private:
    stack<pair<int,int>> st;
public:

    void push(int val){
        if (st.empty()){
            st.push({val, val});
        }else{
            int current_min = st.top().second;
            st.push({val, min(val,current_min)});
        }
    }

    void pop(){
        if(!st.empty()){
            st.pop();
        }
    }

    int top(){
        if(st.empty()) return -1;
        return st.top().first;
    }

    int getMin(){
        if(st.empty()) return -1;
        return st.top().second;
    }
};


int main(){
    MinStackPairs s;
    s.push(12);
    s.push(15);
    s.push(50);
    s.push(10);
    s.push(20);
    s.push(5);

    cout << "--- Pair Approach ---" << endl;
    cout << "Minimum: " << s.getMin() << endl; // 10
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 15
    cout << "Minimum now: " << s.getMin() << endl; // 12

    return 0;
}