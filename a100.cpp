#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxLen(vector<int>&arr, int n){
        // TODO
        unordered_map<int,int> prefix_sum;
        int max_length = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum = sum+arr[i];
            if(sum == 0) max_length = i+1;
            else {
                if(prefix_sum.find(sum) != prefix_sum.end())
                    max_length = max(max_length, i-prefix_sum[sum]);
                else
                    prefix_sum[sum] = i;
            }
        }

        return max_length;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0;
}

