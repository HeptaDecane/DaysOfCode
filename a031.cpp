#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    string removeDups(string s){
        // TODO
        string ans;
        bool char_map[256] = {false};

        for(char ch : s){
            if(not char_map[int(ch)])
                ans += ch;

            char_map[int(ch)] = true;
        }

        return ans;
    }
};

int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;


        Solution ob;
        cout << ob.removeDups(s) << "\n";

    }

    return 0;
}