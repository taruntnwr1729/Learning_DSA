#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double multiply(double number, int n, double target){
    double ans = 1;
    for(int i = 1; i<= n; i++){
        ans = ans*number;
        if(ans>target) return ans;
    }
    return ans;
}

double getNthRoot(int n, int m){
    if(m==0){
        return 0.0;
    }
    double low = 0;
    double high = max(1.0, (double)m);
    double eps = 1e-6;
    while(high-low>eps){
        double mid = low + (high - low)/2;
        if(multiply(mid, n, m)<m){
            low = mid;
        } else{
            high = mid;
        }
    }
    return low;
}

int main(){
    int n, m;

    if(cin>>n>>m){
        double result = getNthRoot(n,m);
        cout<<"Binary Search Result: "<<result<<endl;

        cout<<"Built in pow Result: "<<pow(m, 1.0/n)<<endl;
    }
    return 0;
}