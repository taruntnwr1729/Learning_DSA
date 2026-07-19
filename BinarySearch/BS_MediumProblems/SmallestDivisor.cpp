#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SumByD(vector <int> arr, int div){
    //THIS FUNCTION EXISTS SO THAT WE CAN
    //CALCULATE IF DIVIDING THE ELEMENTS OF ARRAY BY A DIVISIOR
    //AND ADDING THEM IS GIVING MINIMUM RESULT OR NOT
    int sum = 0;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        sum = sum + ceil(double(arr[i])/double(div));
    }

    return sum;
}

int smallDivisor(vector <int> arr, int limit){

    int low = 1; int high = *max_element(arr.begin(), arr.end());
    
    while(low<=high){
        int mid = low + (high - low)/2;
        if(SumByD(arr,mid)<= limit){
            high = mid - 1;

        }else{
            low = mid+1;
        }
    }

    return low;
}