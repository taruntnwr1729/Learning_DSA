#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int missingNo(vector <int> arr, int N){
    int missingNo;
    int sum = 0;
    int OriginalSum = (N*(N+1))/2;

    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
    }
    missingNo = OriginalSum - sum;

    return missingNo;
}

int main(){
    vector <int> arr = {1,2,3,5,6,7};

    return 0;

}