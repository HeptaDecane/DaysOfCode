#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt){
        // TODO
        vector<bool> char_set(256, false);
        for(char ch : patt)
            char_set[ch] = true;

        for(int i=0; i<str.length(); i++){
            if(char_set[str[i]])
                return i;
        }

        return -1;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
    return 0;
}

