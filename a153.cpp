#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int count(int coins[], int n, int sum) {
        // TODO
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
