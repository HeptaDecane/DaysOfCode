#include "bits/stdc++.h"
using namespace std;


class Solution{
public:
    long long int optimalKeys(int n){
        // TODO
        if(n<=6) return n;

        vector<long long int> dp(n+1);
        for(int i=0; i<=6; i++) dp[i] = i;

        for(int i=7; i<=n; i++){
            int repeat = 2;
            for(int j=i-3; j>=1; j--){
                long long int ans = dp[j]*repeat;
                dp[i] = max(dp[i], ans);
                repeat++;
            }
        }

        return dp[n];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.optimalKeys(N) << "\n";
    }
    return 0;
}