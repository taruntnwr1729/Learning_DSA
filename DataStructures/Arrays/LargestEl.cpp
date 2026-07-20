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
        if(arr[j]>SecondLargest & arr[j] != max){
            SecondLargest = arr[j];
        }
    }
    return SecondLargest;
}

int SecondSmallest(vector <int> arr){
    int Smallest = INT_MAX;
    int SecondSmallest = INT_MAX;
    int n = arr.size();

    for(int i = 0; i<n ; i++){
        if(arr[i]<Smallest){
            Smallest = arr[i];

        }else if(arr[i]!=Smallest & arr[i]< SecondSmallest){
            SecondSmallest = arr[i];
        }
    }

    return SecondSmallest;
}
bool isSorted(vector <int> arr){
    int n = arr.size();
    for(int i = 1; i<n;i++){
        if(arr[i]>=arr[i-1]){
            
        }else{
            
            return false;
        }
    }
    return true;
}

int removeDuplicates(vector <int> arr){
    int i = 0;
    int n = arr.size();

    for(int j = 1; j<n; j++){
        if(arr[i] != arr[j]){
            i++;
        }
    }
    return i+1;
}

int main(){
    vector<int> arr = {1,2,3,66,5,4,32,7};
    cout<<"Largest element: "<<Largestelement(arr)<<endl;
    cout<<"Second Largest Element: "<<SecondLargest(arr)<<endl;
    cout<<"Second Smallest Element: "<<SecondSmallest(arr)<<endl;
    return 0;
}