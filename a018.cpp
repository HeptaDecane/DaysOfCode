#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> a, int n){
        // TODO
        vector<vector<int>> result;
        vector<int> entry;
        for(int i=0; i+1<n; i++){
            if(a[i] < a[i+1] and entry.empty())
                entry.push_back(i);
            if(a[i] > a[i+1] and not entry.empty()){
                entry.push_back(i);
                result.push_back(entry);
                entry.clear();
            }
        }

        if(not entry.empty()){
            entry.push_back(n-1);
            result.push_back(entry);
        }

        return result;
    }
};


int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}
