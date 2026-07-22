#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string TwoSum(vector <int> arr, int target){
    int n = arr.size();
    int left = 0;
    int right = n - 1;

    sort(arr.begin(),arr.end());
    int sum = 0;

    while(left<right){
        sum = arr[left] + arr[right];
        if(sum == target){
            return "YES";
        }else if(sum<target){
            left++;  
        }else{
            right--;
        }

    }
    return "NO"

}

int main(){

    return 0;
}