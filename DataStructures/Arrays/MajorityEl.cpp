#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Better Approach O(N)
int MajorityElement(const vector <int> arr){
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

//Moore's Algorithm
int MajorityEl(const vector <int> arr){
    int count = 0;
    int el ;
    int n = arr.size();
    for(int i =0; i<n;  i++){
        if(count == 0){
            count = 1;
            el = arr[i];
        }else if (arr[i] == el){
            count++;
        }else{
            count--;

        }
    }
    int count1 = 0;

    for(int i =0; i<n ; i++){
        if(arr[i]==el){
            count1++;
        }

    }
    if(count1 > n/2){
        return el;
    }
    return -1;

}

int main(){

    return 0;
}