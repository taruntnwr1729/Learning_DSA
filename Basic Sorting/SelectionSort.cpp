/*
Learning Note: So in selection sort what we do is we take an array 
and then we run two nested loops which makes the algorithm of O(n^2) complexity,
we start from the zeroeth indexed element, assume it to be the minimum no. 
and then we run 2nd loop to find lesser no. than it and when we find we swap this no.
with the first indexed  */

#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){

    for(int i=0; i<n-1; i++){  //starting with the zeroth index element
        int minindex = i;

        for(int j=i+1; j<n;j++){
            if (arr[minindex]>arr[j]){      //compare it with every no.
                minindex = j;              //assign minimum index to smaller no.

                 }

            }
            int temp = arr[minindex]; //swap after you have decided this the smallest no. from the remaining array
                arr[minindex] = arr[i];
                arr[i] = temp;
                /* what mistake I was doing is I was putting this block in the 2nd for loop 
                    so it was eventually giving me the required output but it was swapping every no.,
                    It will take more time if we do it*/ 
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

