#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int target)
    {
        // TODO
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> dp(target+1, 1e9);
        vector<int> track(target+1, -1);

        dp[0] = 0;

        for(int j=0; j<coins.size(); j++){
            int coin = coins[j];
            for(int i=1; i<=target; i++){
                if(coin<=i and dp[i]>dp[i-coin]+1){
                    dp[i] = dp[i-coin]+1;
                    track[i] = j;
                }
            }
        }

        vector<int> res;
        if(track[track.size()-1] == -1) return res;

        int i = track.size()-1;
        while (i != 0){
            int j = track[i];
            res.push_back(coins[j]);
            i = i-coins[j];
        }

        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}