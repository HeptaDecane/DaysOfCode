#include "bits/stdc++.h"
using namespace std;


class Solution{
public:
    long long int optimalKeys(int n){
        // TODO
        if(n < 7) return n;

        long long int ans = 0;
        int factor = 2;
        for(int i=n-3; i>=0; i--){
            long long int curr = factor * optimalKeys(i);
            factor++;
            ans = max(ans, curr);
        }
        return ans;
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