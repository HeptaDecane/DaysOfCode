#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long sum){
        // TODO
        vector<int> indices;
        int cur_sum = 0;
        int start = 0;

        for(int i=0; i<n; i++){
            cur_sum = cur_sum+arr[i];

            while(cur_sum>sum){
                cur_sum = cur_sum-arr[start];
                start++;
            }

            if(cur_sum == sum){
                indices.push_back(start+1);
                indices.push_back(i+1);
                break;
            }
        }

        if(indices.empty()) indices.push_back(-1);
        return indices;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);

        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;

    }
    return 0;
}

