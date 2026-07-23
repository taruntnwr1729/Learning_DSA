#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int MaxSubArr(const vector <int> arr){
    int sum = 0;
    int n = arr.size();
    int maxi = INT_MIN;
    int ans_start = -1;
    int ans_end = -1;


    for(int i = 0; i<n; i++){
        if(sum==0){
            sum = sum + arr[i];
        }
        if(sum>maxi){
            maxi = sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}