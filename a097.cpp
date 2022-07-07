#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<string> res;
    vector<string> genIp(string &s) {
        // TODO
        genIp(s,0,0,"");
        return res;
    }

    void genIp(string &s, int idx, int dots, string ip){
        if(dots==3){
            if(idx<s.length() and is_subnet(s.substr(idx)))
                res.push_back(ip+s.substr(idx));
            return;
        }
        if(idx+1<=s.length() and is_subnet(s.substr(idx,1)))
            genIp(s, idx+1, dots+1, ip+s.substr(idx,1)+".");
        if(idx+2<=s.length() and is_subnet(s.substr(idx,2)))
            genIp(s, idx+2, dots+1, ip+s.substr(idx,2)+".");
        if(idx+3<=s.length() and is_subnet(s.substr(idx,3)))
            genIp(s, idx+3, dots+1, ip+s.substr(idx,3)+".");
    }

    bool is_subnet(string s){
        if(s.length()<1 or s.length()>3) return false;

        if(s[0]=='0'){
            if(s.length()==1) return true;
            else return false;
        }

        int net = stoi(s);
        if(0<=net and net<=255) return true;
        return false;
    }

};


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else {
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}