#include <iostream>
#include <climits>
#include<algorithm>
#include <vector>
#include <cmath>
using namespace std;

void Reverse(vector<int> arr,int start, int end){



    while(start<=end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }


}

vector <int> RotateArr(vector<int>arr){
    int n = arr.size();
    int temp = arr[0];
    for(int i =1; i<n; i++){
        arr[i-1]=arr[i];

    }
    arr[n-1]=temp;
    return arr;
}

vector<int> LeftRotate(vector<int> arr, int d) {
    int n = arr.size();
    if (n == 0) return arr;
    
   
    d = d % n; 

    
    reverse(arr.begin(), arr.begin() + d); //we break the array in two and reversed them individually

    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());//then we combined the two reversed arrays and reversed them combined

    return arr;
}

vector<int> MoveZero(vector<int> arr){
    int n = arr.size();
    if(n==0){
        return arr;
    }
    int j = -1;
    for(int i = 0; i<n ; i++){
        if(arr[i]== 0){
            j = i;
            break;
        }
    }
    if(j == -1){
        return arr; //it means no zeroes found
    }

    for(int i = j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    return arr;


}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2; 

    vector<int> Rarr = LeftRotate(arr, d);

    for (int i = 0; i < Rarr.size(); i++) {
        cout << Rarr[i] << " ";
    }

    return 0;
}