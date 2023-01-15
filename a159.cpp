#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // TODO
        const long long MOD = 1e9+7;
        vector<long> dp(n+1,0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1]%MOD + dp[i-2]%MOD + dp[i-3]%MOD;
            dp[i] = dp[i]%MOD;
        }

        return dp[n];
    }
};


int main()
{
    //taking testcases
    int t;
    cin >> t;

    while(t--)
    {
        //taking number of steps in stair
        int n;
        cin>>n;
        Solution ob;
        //calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;

}
