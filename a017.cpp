#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        // TODO
        sort(a.begin(), a.end());

        long long min_diff = LONG_LONG_MAX;
        for(int i=0; i+m-1<n; i++)
            min_diff = min(min_diff, a[i+m-1]-a[i]);

        return min_diff;
    }
};

int main() {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> a;
        long long x;
        for(long long i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }

        long long m;
        cin>>m;
        Solution ob;
        cout<<ob.findMinDiff(a,n,m)<<endl;
    }
    return 0;
}