#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxBalls(int n, int m, vector<int> a, vector<int> b){
        // TODO

    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        vector<int> a(N), b(M);
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];

        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}
