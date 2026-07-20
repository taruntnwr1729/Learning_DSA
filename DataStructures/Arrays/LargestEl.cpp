#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Largestelement(vector<int> arr){
    int n = arr.size();
    int max = INT_MIN;
    for(int i = 0; i<n;i++){
        if(arr[i]>max){
            max = arr[i];

        }

    }
    return max;
}

int main(){
    vector<int> arr = {1,2,3,66,5,4,32,7};
    cout<<"Largest element: "<<Largestelement(arr)<<endl;
    return 0;
}