#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> find_permutation(string s){
        // TODO
        set<string> permutations;
        permute(permutations, s, 0, s.length()-1);
        return vector<string>(permutations.begin(), permutations.end());
    }

    void permute(set<string> &permutations, string s, int l, int r){
        if (l == r)
            permutations.insert(s);
        else
            for(int i=l; i<=r; i++){
                swap(s[l], s[i]);
                permute(permutations, s, l+1, r);
                swap(s[l], s[i]);
            }
    }
};


int main(){
    int t;
    cin >> t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}