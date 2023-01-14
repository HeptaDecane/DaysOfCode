#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    int minDifference(int arr[], int n)  {
        // TODO
        int sum = accumulate(arr,arr+n,0);
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i=0; i<=n; i++) dp[i][0] = true;

        for(int i=1; i<=n; i++){
            int element = arr[i-1];
            for(int j=1; j<=sum; j++){
                if(element > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-element];
            }
        }

        int min_diff = sum;
        for(int j=0; j<=sum; j++){
            if(dp[n][j])
                min_diff = min(min_diff, abs(sum-2*j));
        }

        return min_diff;
    }
};

int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}
