#include "bits/stdc++.h"
using namespace std;


long long  numberOfPaths(int m, int n){
    // TODO
    vector<int> dp(n, 1);

    for(int i=0; i<m-1; i++){
        for(int j=1; j<n; j++)
            dp[j] += dp[j-1];
    }
    return dp[n-1];
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