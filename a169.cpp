#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // TODO
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        int arr1[n],arr2[m];
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<m;i++)
            cin>>arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
    }
    return 0;
}
