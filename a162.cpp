#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n)
    {
        // TODO
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return m+n-dp[m][n];
    }
};


int main()
{

    int t;

    //taking total testcases
    cin >> t;
    while(t--){
        string X, Y;
        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
    return 0;
}
