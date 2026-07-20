#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
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

int SecondLargest(vector <int> arr){
    int SecondLargest = INT_MIN;
    int n = arr.size();
    int max = INT_MIN;
    for(int i = 0; i<n;i++){
        if(arr[i]>max){
            max = arr[i];

        }

    }
    for(int j = 0; j<n;j++){
        if(arr[j]>SecondLargest & arr[j]< max){
            SecondLargest = arr[j];
        }
    }
    return SecondLargest;
}

int main(){
    vector<int> arr = {1,2,3,66,5,4,32,7};
    cout<<"Largest element: "<<Largestelement(arr)<<endl;
    return 0;
}