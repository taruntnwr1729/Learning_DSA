#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric> // Needed for std::accumulate

using namespace std;

int FindDays(const vector<int>& arr, int capacity){
    int days = 1;
    int load = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        // If adding this package exceeds capacity, ship current load and move to next day
        if (load + arr[i] > capacity) {
            days += 1;
            load = arr[i]; // The current package starts the new day's load
        } else {
            load += arr[i];
        }
    }

    return days;
}

int leastWeight(const vector<int>& arr, int d){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = low + (high - low) / 2;

        int numberofdays = FindDays(arr, mid);
        if(numberofdays <= d){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Added 2 to complete standard test case
    int days = 5;
    
    cout << "Least conveyor capacity required: " << leastWeight(arr, days) << endl;
    return 0;
}