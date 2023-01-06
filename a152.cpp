#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int editDistance(string str1, string str2) {
        // TODO
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=0; i<=m; i++) dp[i][0]=i;
        for(int i=0; i<=n; i++) dp[0][i]=i;

        // diagonal - EDIT
        // left - DELETE
        // top - INSERT

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(str1[i] == str2[j])
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = min({dp[i+1][j], dp[i][j+1], dp[i][j]})+1;
            }
        }

        return dp[m][n];
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}