#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // TODO
        int dp[n+1][m+1];

        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int i=0; i<=m; i++) dp[0][i]=0;

        // build dp matrix
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                char ch1 = s1[i-1];
                char ch2 = s1[j-1];

                if(ch1 == ch2)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = 0;
            }
        }

        int length = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++)
                length = max(length, dp[i][j]);
        }
        return length;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}