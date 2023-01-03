#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int weights[], int values[], int n)
    {
        // TODO
        vector<vector<int>> dp(n+1,vector<int>(w+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                int weight = weights[i-1];
                int value = values[i-1];

                if(weight > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(value+dp[i-1][j-weight], dp[i-1][j]);
            }
        }

        return dp[n][w];
    }
};

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
    return 0;
}
