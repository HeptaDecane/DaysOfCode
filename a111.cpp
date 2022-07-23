#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string UncommonChars(string a, string b){
        // TODO
        bool char_set_a[256] = {false};
        for(char ch : a) char_set_a[ch] = true;

        bool char_set_b[256] = {false};
        for(char ch : b) char_set_b[ch] = true;

        string res;
        for(char ch='a'; ch<='z'; ch++){
            if(char_set_a[ch] != char_set_b[ch])
                res += ch;
        }
        return res.length() ? res : "-1";
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
