#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // TODO
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            if(i>=x && dp[i-x]>=0) dp[i] = max(dp[i], dp[i-x]+1);
            if(i>=y && dp[i-y]>=0) dp[i] = max(dp[i], dp[i-y]+1);
            if(i>=z && dp[i-z]>=0) dp[i] = max(dp[i], dp[i-z]+1);
        }

        return max(dp[n],0);
    }
};

int main() {

    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

    return 0;
}
