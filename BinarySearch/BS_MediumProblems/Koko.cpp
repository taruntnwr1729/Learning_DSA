#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int findMax(vector<int> &arr){
    int maxi = INT_MIN;
    int n = arr.size();

    for(int i =0 ; i<n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> & arr, int hourly){
    int totalH = 0;
    int n = arr.size();

    for(int i = 0; i<n; i++){
        totalH += ceil((double)arr[i]/ (double)hourly);
    }

    return totalH;
}

int minRateToEatBananas(vector <int> arr, int h){
    int low = 1;
    int high = findMax(arr);
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int totalH = calculateTotalHours(arr, mid);
        if(totalH<= h){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}



int main(){
    vector<int> arr = {3,4,5,7,11};
    int hour = 8;
    int minSpeed = minRateToEatBananas(arr, hour);
    cout << "Minimum rate to eat bananas: " << minSpeed << " bananas/hour" << endl;
    return 0;
}