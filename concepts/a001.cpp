#include "bits/stdc++.h"
using namespace std;

string longest_common_subsequence(string a, string b){
    int m = a.length();
    int n = b.length();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) dp[i][0]=0;
    for(int i=0; i<=n; i++) dp[0][i]=0;

    // build dp matrix
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            char ch1 = a[i-1];
            char ch2 = b[j-1];

            if(ch1 == ch2)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // print dp matrix
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }

    // traverse dp and find lcs
    string res;
    int i=m, j=n;
    while (i>=0 and j>=0){
        if(dp[i-1][j] == dp[i][j])
            i--;
        else if(dp[i][j-1] == dp[i][j])
            j--;
        else{
            res += a[i-1];
            i--, j--;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string a = "hello";
    string b = "halo";

    cout<<longest_common_subsequence(a, b)<<"\n";
    return 0;
}