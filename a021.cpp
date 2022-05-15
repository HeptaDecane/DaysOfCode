#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lastIndex(string s){
        // TODO
        for(int i=s.length()-1; i>=0; i--)
            if(s[i]=='1')   return i;

        return -1;
    }

};


int main() {
    long long t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.lastIndex(s) << endl;
    }
    return 0;
}