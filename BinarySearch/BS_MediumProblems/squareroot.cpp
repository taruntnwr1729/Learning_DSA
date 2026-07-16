#include <iostream>
#include <vector>
using namespace std;

int SquareRoot(int arr, int n, int val){
    if (val<2){
        return 1;
    }
    
    int low = 0;
    int high = n;
    int ans = 0;

    while(low<=high){
        long long mid = low + (high - low)/2;
        int square = mid*mid;
        if(square == val){
            return mid;
        }else if(square>mid){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }

    }
    
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int n = arr.size();
    

    return 0;
}