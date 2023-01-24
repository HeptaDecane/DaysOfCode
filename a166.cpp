#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // TODO
    int get_mid_sum(int *arr, int n)
    {
        return n%2==0 ? arr[n/2]+arr[n/2 - 1] : 2*arr[n/2];
    }

    int findMidSum(int a[], int b[], int n) {
        // TODO
        if(n<=0) return -1;
        if(n==1) return a[0]+b[0];
        if(n==2) return max(a[0],b[0]) + min(a[1],b[1]);

        int m1 = get_mid_sum(a,n);
        int m2 = get_mid_sum(b,n);

        if(m1 < m2){
            if(n%2 == 0)
                return findMidSum(a + n/2 - 1, b, n - n/2 + 1 );
            else
                return findMidSum(a + n/2, b, n - n/2);
        }

        else if (m1 > m2){
            if(n%2 == 0)
                return findMidSum(b + n/2 - 1, a, n - n/2 + 1 );
            else
                return findMidSum(b + n/2, a, n - n/2);
        }

        else
            return m1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
