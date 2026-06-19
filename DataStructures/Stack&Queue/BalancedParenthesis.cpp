#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expr){
    stack<char> s;

    for(char ch : expr){
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if ( ch == ')' || ch =='}' || ch == ']'){
            if (s.empty()){
                return false;
            }

            char topchar = s.top();

        if((ch==')' && topchar == '(') ||
            (ch=='}' && topchar == '{') ||
            (ch==']' && topchar == '[')){
            s.pop();
            }else{
                return false; 
            }
        }
    }
    return s.empty();
}

int main(){

    string expr1 = "{[[(){}]{()}]}";
    string expr2 = "{(})";

    cout << expr1 << " is " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " is " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}