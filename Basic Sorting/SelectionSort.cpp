#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        int minindex = i;

        for(int j=i+1; j<n;j++){
            if (arr[minindex]>arr[j]){
                minindex = j;

                
                }
            }
            int temp = arr[minindex];
                arr[minindex] = arr[i];
                arr[i] = temp;

    }


    
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]); 
    

    selection_sort(arr, n);

    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    

    return 0;
}