#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int missingNo(vector <int> arr, int K){
    int low = 0;
    int n = arr.size();
    int high = n -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid+1);
        if(missing<K){
            low = mid + 1;

        }else{
            high = mid - 1;
        }
    }

    return (low + K);
}
int main(){
    vector <int> arr = {2,3,4,5,7,9,11};
    int K = 6;
    cout<<"Missing no: "<<missingNo(arr, K);



    return 0;
}