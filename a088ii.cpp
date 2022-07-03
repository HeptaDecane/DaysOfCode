#include "bits/stdc++.h"
using namespace std;


long long  numberOfPaths(int m, int n){
    // TODO
    vector<vector<int>> dp(m, vector<int>(n,1));

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    return dp[m-1][n-1];
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        cout << numberOfPaths(m, n)<<endl;
    }
    return 0;
}