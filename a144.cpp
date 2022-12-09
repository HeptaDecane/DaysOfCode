#include <bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};

class Solution{
public:
    // TODO
    static bool val_comparator(struct val a, struct  val b){
        return a.first < b.first;
    }

    int maxChainLen(struct val pairs[],int n){
        // TODO
        sort(pairs, pairs+n, val_comparator);

        vector<int> dp(n,1);

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j].second < pairs[i].first)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};


int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        val p[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].first>>p[i].second;
        }
        Solution ob;
        cout<<ob.maxChainLen(p,n)<<endl;
    }
    return 0;
}
