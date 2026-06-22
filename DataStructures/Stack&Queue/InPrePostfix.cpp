#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string InfixToPostfix(string S ){

    int i = 0;
    int n = S.length();
    stack<char> st;
    string ans = "";

    while(i<n){ //Iterate the whole string

        if ((S[i] >= 'A' && S[i]<='Z') || (S[i] >= 'a' && S[i]<='z') || (S[i]>= '0' && S[i]<='9')){
            //add into S string if it is A to Z or 0 to 9
            ans = ans + S[i];
            
        }else if(S[i] == '('){
            //Push Opening bracket only
            st.push(S[i]);

        }else if(S[i]==')'){
            //When a closing bracket is detected 
            while(!st.empty() && st.top() != '('){//empty the whole stack until you see a opening bracket
                ans = ans + st.top();
                st.pop();

            }
            if(!st.empty()) st.pop();

        }else{
            while(!st.empty() && (priority(S[i])<= priority(st.top()))){
                ans = ans + st.top();
                st.pop();

            }
            st.push(S[i]);
        }
        
        i++;
    }

    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}
int main(){

    string exp = "a+b*(c^d-e)";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << InfixToPostfix(exp) << endl;
    return 0;


    return 0;
}