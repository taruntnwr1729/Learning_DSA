#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;
//This a better approach not the best
int LongestSubArr(vector <int> arr, long long K){
    unordered_map<long long, int> PreSumMap;
    long long sum = 0;
    int maxlen = 0;
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        sum += arr[i];
        
        if(sum == K){
            maxlen = max(maxlen, i + 1);
        }
        long long rem = sum - K;

        if(PreSumMap.find(rem) != PreSumMap.end()){
            int len = i - PreSumMap[rem];
            maxlen = max(maxlen, len);
        }
        if (PreSumMap.find(sum) == PreSumMap.end()) {
            PreSumMap[sum] = i;
        }
    }

    return maxlen;
}

int LongestSubArray(vector <int> arr, long long K){
    int i = 0;
    int j = 0;
    int n = arr.size();
    long long sum = 0;
    int maxlen = 0;

    for(int i = 0; i<n; i++){
        sum = sum + arr[i];
        while(j<=i && sum>K){
            sum = sum - arr[j];
            j++;
        }if(sum == K){
            maxlen = max(maxlen,i-j+1);
        }
        
    }
    return maxlen;
}

int main(){
    vector <int> arr = {1,2,1,1,3,2,1,1,1,4,2,5};
    int K = 3; //Sum must be three
}