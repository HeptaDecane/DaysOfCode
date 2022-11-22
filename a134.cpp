//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int toyCount(int n, int k, vector<int> arr)
    {
        // TODO
        sort(arr.begin(), arr.end());

        int count = 0;
        for(int cost : arr){
            if(k >= cost){
                count++;
                k = k-cost;
            }
            else break;
        }

        return count;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.toyCount(N, K, arr)<<endl;
    }
    return 0;
}
