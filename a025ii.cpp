#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> find_permutation(string s){
        // TODO
        set<string> permutations;
        permute(permutations, s);
        return vector<string>(permutations.begin(), permutations.end());
    }

    void permute(set<string> &permutations, string s, string permutation=""){
        if (s.length() == 0)
            permutations.insert(permutation);
        else
            for(int i=0; i<s.length(); i++){
                char ch = s[i];
                string rest = s.substr(0,i) + s.substr(i+1);
                permute(permutations, rest, permutation+ch);
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