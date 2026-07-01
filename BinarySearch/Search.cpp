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

        //this condition is for arrays like {3,1,2,3,3,3}
        if(arr[low]==arr[mid]==arr[high]){
            low++, high--;
            continue;
        }

        //left half sorted
        //we check if the low element is really lesser than mid element
        //then we check if my target lies in the range of low and mid elements
        //if it is true then we conclude that the left half is sorted and our element lies in it
        //so we take our high to mid-1, and scraps the right half of the array to find our target
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

int FindMin(vector<int> &arr, int n, int target){

    int low = 0;
    int high = n-1;
    int ans = INT_MAX;

    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[mid]);
            low = mid+1;

        }else{
            high = mid-1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
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