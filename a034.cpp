#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*You are required to complete this method */
    int atoi(string str) {
        // TODO
        int start = 0, sign = 1;
        int num = 0;
        if(str[0] == '-')
            start++, sign = -1;

        for(int i=start; i<str.length(); i++){
            if(not isdigit(str[i]))
                return -1;

            num = num*10 + int(str[i]-'0');
        }

        return sign * num;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.atoi(s)<<endl;
    }
}