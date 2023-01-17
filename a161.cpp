#include <bits/stdc++.h>
using namespace std;


//Function to find the maximum possible amount of money we can win.
class Solution{
public:
    long long maximumAmount(int arr[], int n){
        // TODO
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n,{0,0}));

        for(int i=0; i<n; i++){
            dp[i][i].first = arr[i];
            dp[i][i].second = 0;
        }

        for(int l=2; l<=n; l++){
            for(int i=0; i<=n-l; i++){
                int j = i+l-1;
                if(arr[i]+dp[i+1][j].second > arr[j]+dp[i][j-1].second){
                    dp[i][j].first = arr[i]+dp[i+1][j].second;
                    dp[i][j].second = dp[i+1][j].first;
                }
                else{
                    dp[i][j].first = arr[j]+dp[i][j-1].second;
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }

        return dp[0][n-1].first;
    }
};

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maximumAmount(a,n)<<endl;
    }
    return 0;
}
