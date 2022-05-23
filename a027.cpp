#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string rremove(string s){
        // TODO
        string ans;
        int i=0, n=s.length();

        while(i < n){
            bool flag = false;
            while (s[i]==s[i+1] and i<n-1){
                i++;
                flag = true;
            }
            if(flag) i++;

            if(i<n and s[i]!=s[i+1]){
                ans += s[i];
                i++;
            }
        }

        if(s.length() == ans.length()) return ans;
        else return rremove(ans);
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}