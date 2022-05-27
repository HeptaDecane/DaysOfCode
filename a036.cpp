#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    string longestCommonPrefix (string arr[], int n){
        // TODO

        string str = arr[0];
        string prefix;

        for(int i=0; i<str.length(); i++){
            char ch = str[i];

            for(int j=0; j<n; j++){
                if (arr[j].length() <= i)
                    return prefix.empty() ? "-1" : prefix;
                if(ch != arr[j][i])
                    return prefix.empty() ? "-1" : prefix;
            }
            prefix += ch;
        }
        return prefix.empty() ? "-1" : prefix;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
