#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BuySell(const vector <int> arr){
    int mini = arr[0];
    int maxProfit = 0;
    int n = arr.size();

    for(int i = 0; i<n ; i++){

        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);

    }

    return maxProfit;
}