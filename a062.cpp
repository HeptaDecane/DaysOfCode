#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    string FirstNonRepeating(string str){
        // TODO
        int char_map[256] = {0};
        string str_ordered;
        string res;

        for (char ch : str){
            if(not char_map[ch]) str_ordered += ch;
            char_map[ch] += 1;

            char temp = '#';
            for(char x : str_ordered){
                if(char_map[x] == 1){
                    temp = x;
                    break;
                }
            }
            res += temp;
        }

        return res;
    }

};


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}