#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToDecimal(string &str) {
        // TODO
        int ans = 0;
        unordered_map<char,int> num = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for(int i=0; i<str.length(); i++){
            if(num[str[i+1]] > num[str[i]] and i<str.length()-1){
                ans += num[str[i+1]] - num[str[i]];
                i++;
            }
            else ans += num[str[i]];
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}