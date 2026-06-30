#include <iostream>
#include <vector>

using namespace std;

//Searching on rotated sorted array

int RotatedSearch(vector<int> &arr, int n, int target){
    int low = 0;
    int high = n -1;

    while (low<=high){
        int mid = low + (low - high)/2;

        if(arr[mid]==target){
            return mid;
        }
        //left half sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target <= arr[mid]){
            high= mid -1;
            }else{
            low = mid+1;
        }
        //right half sorted
    }else{
        if(arr[mid]<= target && target <= arr[high]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    }
    return -1;
}

int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int n = arr.size();

    int target = 2;

    int result = RotatedSearch(arr, n, target);
    
    if(result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}