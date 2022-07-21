#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        // TODO
        unordered_map<ll,ll> prefix_sum_map;
        ll sum = 0, count = 0;

        prefix_sum_map[0] = 1;
        for(ll element : arr){
            sum = sum + element;
            count = count + prefix_sum_map[sum];
            prefix_sum_map[sum]++;
        }
        return count;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array

        vector<ll> arr(n,0);

        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
    return 0;
}
