#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    int maxSumIS(int arr[], int n)
    {
        // TODO
        vector<int> dp(arr, arr+n);

        vector<int> track(n);
        for(int i=0; i<n; i++) track[i]=i;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i] and dp[i]<dp[j]+arr[i]){
                    dp[i] = dp[j]+arr[i];
                    track[i] = j;
                }
            }
        }

        // track array can be used to obtain the actual sequence
        // refer: https://www.youtube.com/watch?v=99ssGWhLPUE

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";

    }
    return 0;
}
