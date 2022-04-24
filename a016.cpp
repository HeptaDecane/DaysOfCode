#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool checkTriplet(int arr[], int n) {
        // TODO
        sort(arr, arr+n);

        for(int i=0; i<n; i++){
            int c2 = arr[i]*arr[i];
            int left = 0;
            int right = i-1;

            while(left < right){
                int a2 = arr[left]*arr[left];
                int b2 = arr[right]*arr[right];

                if(a2+b2 < c2) left++;
                else if(a2+b2 > c2) right--;
                else return true;

            }
        }

        return false;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
