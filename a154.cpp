#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // TODO
        int sum=0;
        for(int i=0; i<n; i++) sum += arr[i];
        if(sum%2 != 0) return 0;

        sum = sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1,false));
        for(int i=0; i<=n; i++) dp[i][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                int element = arr[i-1];

                if(element > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-element];
            }
        }

        return dp[n][sum];
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
