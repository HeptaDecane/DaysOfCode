#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int count(int coins[], int n, int sum) {
        // TODO
        vector<vector<long long int>> dp(n+1,vector(sum+1,0ll));

        for(int i=0; i<=n; i++) dp[i][0]=1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                int coin = coins[i-1];

                if(coin > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-coin] + dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}
