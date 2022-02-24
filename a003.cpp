#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        // TODO
        int local_max = arr[0];
        int global_max = local_max;

        for(int i=1; i<n; i++){
            local_max = max(arr[i], local_max+arr[i]);
            global_max = max(local_max, global_max);
        }

        return global_max;
    }
};

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
