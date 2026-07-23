#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector <int> NextPermutation(vector <int> arr){
    int n = arr.size();
    int index = -1;
    //in this algo what we are doing is, we are trying to find
    //left element which is smaller than it's right element
    for(int i = n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            index = i; // we store its index when we find it
            break;  
        }

    }

    if(index == -1){
        reverse(arr.begin(),arr.end());
    }

    for(int i = n-1 ; i>=index; i++){ // then we find the just 1 no. big element starting from right side 
        if(arr[i]>arr[index]){ // of the array
            swap(arr[i],arr[index]); //then we swap it with that element. for eg: if it is 3 then we will try to find 4
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());

    return arr; 
}