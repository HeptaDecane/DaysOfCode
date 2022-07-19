#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x){
        // TODO
        sort(a, a+n);
        sort(b, b+m);

        vector<pair<int,int>> res;
        int i=0, j=m-1;

        while (i<n and j>=0){
            if(a[i]+b[j] < x) i++;
            else if(a[i]+b[j] > x) j--;
            else {
                res.push_back({a[i], b[j]});
                i++, j--;
            }
        }
        return res;
    }
};


int main() {
    long long t;
    cin >> t;

    while(t--){
        int N, M, X;
        cin >> N >> M >> X;
        int A[N], B[M];

        for(int i = 0;i<N;i++)
            cin >> A[i];
        for(int i = 0;i<M;i++)
            cin >> B[i];

        Solution ob;
        vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
        int sz = vp.size();
        if(sz==0)
            cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                    cout<<vp[i].first<<" "<<vp[i].second;
                else
                    cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
    }
    return 0;
}
