#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Better Approach
int MajorityElement(vector <int> arr){
    int n = arr.size();
    unordered_map <int,int> Map;

    for(int i = 0; i<n ; i++){
        Map[arr[i]]++;
    }

    for(auto it: Map){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}

int main(){

    return 0;
}