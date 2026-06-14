#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n){
    
    for(int i = 1; i < n; i++){
        int j = i;
        
        
        while(j > 0 && arr[j-1] > arr[j]){
            
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            
            j--; 
        }
    }
    
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]); 

    InsertionSort(arr, n);

    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}