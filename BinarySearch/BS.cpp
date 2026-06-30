#include <iostream>
#include <vector>
using namespace std;

int upperbound(vector<int> &arr, int x, int n ){
    int low = 0, high = n - 1;
    int ans = n;
    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid+1;
        }

    }
    
    return ans;

}

int lowerbound(vector<int> &arr, int x, int n ){
    int low = 0, high = n - 1;
    int ans = n;
    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid]>=x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid+1;
        }

    }
    
    return ans;

}

//IF SOMEONE ASKS ME TO TELL THE RANGE OF THE SAME ELEMENT OCCURING CONSECUTEVILY WE CAN TELL IT BY USING LOWER BOUND AND UPPERBOUND
pair<int,int>RangeofEl(vector<int> &arr, int x, int n){
    int lb = lowerbound(arr, x, n);
    if(lb==n || arr[lb] != x) return {-1, -1};
    return {lb, (upperbound(arr,x,n)-1)};

}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7,7,8,9,10,11,11,12,13};
    int n = arr.size();
    int x = 9;
    int indexUP = upperbound(arr, x, n);
    int indexLOW = lowerbound(arr, x, n);
    cout<<"The upperbound of "<< x <<" is at index: "<<indexUP<<endl;
    cout<<"The value at that index is:" << arr[indexUP]<<endl;

    cout<<"The lowerbound of "<< x <<" is at index: "<<indexLOW<<endl;
    cout<<"The value at that index is:" << arr[indexLOW]<<endl;

    pair<int, int> range = RangeofEl(arr, x, n);
    cout << "Range is: [" << range.first << ", " << range.second << "]" << endl;

    return 0;
}