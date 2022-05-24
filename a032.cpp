#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countMin(string str){
        // TODO
        int n = str.length();
        string str_rev = str;
        reverse(str_rev.begin(), str_rev.end());

        int dp[n+1][n+1];
        for(int i=0; i<=n; i++){
            dp[0][i] = 0;
            dp[i][0] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                char ch1 = str[i-1];
                char ch2 = str_rev[j-1];

                if(ch1 == ch2)
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}
