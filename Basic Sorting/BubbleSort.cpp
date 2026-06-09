#include <iostream>
using namespace std;

void bubble_sort(int arr[],int n ){
    int loopcounter = 0;
    for(int i = n-1; i>=1; i--){
        int didswap =0;
        
        loopcounter++;
        for(int j = 0; j<=i-1 ; j++){
            
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j] = temp;
                didswap = 1;
            }

        }
        if(didswap == 0){
            break;
        }
     
}
    cout<<"loopcounter : "<<loopcounter<<endl;

}
    



int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]); 

    bubble_sort(arr, n);

    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    return 0;
}