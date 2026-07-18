#include <iostream>
#include<cmath>
#include<algorithm>
#include <vector>
#include <climits>

using namespace std;

int possible(vector<int> arr, int day, int m, int k){
    int counter = 0;
    int Bouqets = 0;
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        if(arr[i]<=day){
            counter++;

        }
        else{
            Bouqets += (counter/k);
            counter = 0;
        }
        
    }
    Bouqets += counter/k;

    return Bouqets >= m;
    
}

int RoseBed(vector <int> arr, int day, int m, int k){
    int n = arr.size();
    long long val = m*1LL*k*1LL;
    if(val>n){
        return -1;

    }

    int mini =INT_MIN; int maxi = INT_MAX;
    for(int i = 0; i<n; i++){
        mini = min(mini , arr[i]);
        maxi = max(maxi,arr[i]);
    }
    int high = maxi;
    int low = mini;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(possible(arr,mid,m,k)){
            high = mid-1;
        }else{
            low = mid+1;
        }
        
    }
    return low;
    
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    return 0;
}