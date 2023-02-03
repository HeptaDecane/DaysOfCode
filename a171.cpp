#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        // TODO
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
