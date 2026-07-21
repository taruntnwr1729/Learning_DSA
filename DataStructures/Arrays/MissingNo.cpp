#include <iostream>
#include <vector>

using namespace std;

int missingNo(const vector<int>& arr) {
    long long N = arr.size() + 1;
    long long sum = 0;
    long long OriginalSum = (N * (N + 1)) / 2;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    return OriginalSum - sum;
}
int ConsecutiveOnes(const vector <int> arr){
    int n = arr.size();
    int maxi = 0;
    int count = 0;

    for(int i = 0; i<n; i++){
        if(arr[i]==1){
            count +=1;
            maxi = max(maxi,count);
        }else{
            count = 0;
        }
    }
    return maxi;
}

int main() {
    vector<int> arr = {1, 2, 3, 5, 6, 7};
    
    int result = missingNo(arr);
    cout << "Missing number is: " << result << endl;

    return 0;
}