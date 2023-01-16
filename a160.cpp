#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int eggDrop(int eggs, int floors)
    {
        // TODO
        vector<vector<int>> dp(eggs+1, vector<int>(floors+1, 0));

        for(int i=0; i<=floors; i++) dp[1][i] = i;

        for(int i=2; i<=eggs; i++){
            for(int j=1; j<=floors; j++){
                if(i > j)
                    dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = INT_MAX;
                    for(int k=1; k<=j; k++){
                        int curr_count = 1 + max(dp[i-1][k-1],dp[i][j-k]);
                        dp[i][j] = min(dp[i][j], curr_count);
                    }
                }
            }
        }

        return dp[eggs][floors];
    }
};


int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
