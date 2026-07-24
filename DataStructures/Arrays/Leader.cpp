#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector <int> LeadersOfArr(vector <int> arr){
    int n = arr.size();
    vector <int> ans;
    int maxi = INT_MIN;

    for(int i = n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);

    }

    sort(ans.begin(),ans.end());
}

int main(){
    return 0;
}