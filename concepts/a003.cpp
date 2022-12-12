#include "bits/stdc++.h"
using namespace std;

int longest_increasing_subsequence(int arr[], int n){
    vector<int> dp(n,1);

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longest_increasing_subsequence(arr,n)<<"\n";
    return 0;
}