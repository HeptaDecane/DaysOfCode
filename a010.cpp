#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int equilibriumPoint(long long arr[], int n) {
        // TODO
        long long right_sum=0;
        for(int i=0; i<n; i++) right_sum+=arr[i];

        long long left_sum=0;
        for(int i=0; i<n; i++){
            right_sum -= arr[i];
            if(left_sum == right_sum)
                return i+1;     // 1-based index
            left_sum += arr[i];
        }
        return -1;
    }

};


int main() {

    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}