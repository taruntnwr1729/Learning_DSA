#include <iostream>
#include <vector>
using namespace std;

//this works only when no. of negatives and positives are same
vector <int> RearrangeElements(const vector <int> arr){
    int n = arr.size();
    vector <int> ans(n,0);
    int posIndex = 0;
    int negIndex = 1;

    for(int i =0; i<n; i++){
        if(arr[i]<0){
            ans[negIndex]=arr[i];

        }else{
            ans[posIndex] = arr[i];
            posIndex +=2;

        }
    }
    return ans;
    
}

vector <int> Rearrange( vector <int> arr){
    int n = arr.size();
    vector <int> pos;
    vector <int> neg;

    //with this loop we made positive and negative arrays
    for(int i =0; i<n ; i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);

        }
    }
    
    //then we checked which array's size is more
    if(pos.size() > neg.size()){ //if positive is greater
        for(int i = 0; i< neg.size(); i++){ //then we run the loop till negative array doesnt end
            arr[2*i] = pos[i];  //we assign even position to positives
            arr[2*i + 1] = neg[i];//and odd position to negatives
        }
        int index = neg.size()*2; //then we do this so that we get the position till the array has been filled
        for(int i = neg.size(); i<pos.size(); i++){ //we start from negative size till positive arrays size
            arr[index] = pos[i]; //assign elements in array;
            index++;
        }
    }else{
        for(int i = 0; i< pos.size(); i++){ //we do this if negative is greater
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i = pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }

    }

    return arr;

}