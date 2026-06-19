#include <iostream>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

/* ----MIN STACK USING PAIRS----*/
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


/*-----MINSTACK USING MATHEMATICAL APPROACH------*/
class MinStackMaths{

private:
    stack<long long> st;
    long long mini;

public:

    MinStackMaths(){
        mini = LLONG_MAX;
    }

    void push(int value){
        long long val = value;
        if(st.empty()){
            mini = val;
            st.push(val);
        }else{
            if(val<mini){
                st.push(2*val - mini);
                mini = val;
            }else{
                st.push(val);
            }
        }
    }

    void pop(){
        if(st.empty()) return;

        long long top_val = st.top();
        st.pop();

        if (top_val < mini){
            mini = 2*mini - top_val;
        }
    }

    int top(){
        if (st.empty())return -1;

        long long top_val = st.top();
        if(top_val < mini){
            return mini;
        }
        return top_val;
    }

    int getMin(){
        if(st.empty()) return -1;

        return mini;
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

    MinStackMaths s1;
    s1.push(12);
    s1.push(15);
    s1.push(50);
    s1.push(10);
    s1.push(20);
    s1.push(50);

    cout << "--- Pair Approach ---" << endl;
    cout << "Minimum: " << s.getMin() << endl; // 10
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 15
    cout << "Minimum now: " << s.getMin() << endl; // 12


    cout << "--- Math Approach ---" << endl;
    cout << "Minimum: " << s1.getMin() << endl; // 10
    s1.pop();
    cout << "Top element after pop: " << s.top() << endl; // 15
    cout << "Minimum now: " << s1.getMin() << endl; // 12

    return 0;
}