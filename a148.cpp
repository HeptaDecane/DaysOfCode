#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;


class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int m, int n, string str1, string str2)
    {
        // TODO
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(str1[i] == str2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[m][n];
    }
};


int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

