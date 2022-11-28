#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        // TODO
        sort(arr, arr+n);

        int shortest,tallest;
        int diff = arr[n-1]-arr[0];

        for(int i=1; i<n; i++){
            if(arr[i]-k < 0) continue;

            shortest = min(arr[0]+k, arr[i]-k);
            tallest = max(arr[n-1]-k, arr[i-1]+k);
            diff = min(diff, tallest-shortest);
        }

        return diff;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
