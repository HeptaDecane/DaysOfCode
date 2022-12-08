#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperation(int n)
    {
        // TODO
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            if(i%2 == 0)
                dp[i] = dp[i/2]+1;
            else
                dp[i] = dp[i-1]+1;
        }
        return dp[n];

        int count = 0;
        while (n>0){
            if(n%2 == 0)
                n=n/2;
            else
                n = n-1;
            count++;
        }
        return count;
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
        Solution ob;
        cout<<ob.minOperation(n)<<endl;
    }
}
