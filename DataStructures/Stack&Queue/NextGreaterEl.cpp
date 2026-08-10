#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector <int> bruteforcefun(vector<int> arr){
    int n = arr.size();
    vector<int> res(n, -1);

    for(int i = 0; i<n; i++){

        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                res[i] = arr[j];
                break;
            }

        }
    }

    return res;

}

vector <int> OptimalFun(vector <int> arr){
    stack <int> st;
    int n = arr.size();
    vector <int> res(n,-1);
   


    for(int i = n-1; i>=0; i--){

        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            res[i] = st.top();
        }

        st.push(arr[i]);    

    
    }
    return res;
}

int main() {
    vector<int> arr = {6, 0, 3, 4, 5, 1};

    vector<int> bruteRes = bruteforcefun(arr);
    vector<int> optimalRes = OptimalFun(arr);

    cout << "Array:        ";
    for (int x : arr) cout << x << " ";
    cout << "\nBrute Force:  ";
    for (int x : bruteRes) cout << x << " ";
    cout << "\nOptimal Stack:";
    for (int x : optimalRes) cout << x << " ";
    cout << endl;

    return 0;
}