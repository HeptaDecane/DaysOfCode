#include "bits/stdc++.h"
using namespace std;

class Solution{
/*
    sum1 - a + b = sum2 - b + a
    2a - 2b  = sum1 - sum2
    a - b  = (sum1 - sum2)/2
    a = (sum1 - sum2)/2 + b
*/
public:
    int findSwapValues(int a[], int n, int b[], int m){
        // TODO
        int sum1 = 0;
        unordered_set<int> set_a;
        for(int i=0; i<n; i++){
            sum1+=a[i];
            set_a.insert(a[i]);
        }

        int sum2 = 0;
        for(int i=0; i<m; i++) sum2+=b[i];

        if((sum1-sum2)%2 != 0)
            return -1;

        int target = (sum1-sum2)/2;
        for(int i=0; i<m; i++){
            if(set_a.find(target+b[i]) != set_a.end())
                return 1;
        }
        return -1;
    }

};


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];


        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
        cout << "\n";

    }
    return 0;
}
