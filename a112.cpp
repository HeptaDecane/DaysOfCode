#include<bits/stdc++.h>
using namespace std;


class Solution{
public:

    //Function to find the smallest window in the string s consisting of all the characters of string p.
    string smallestWindow (string s, string p){
        // TODO
        vector<int> freq_map(256,0);
        vector<int> freq_map_p(256,0);
        string res = "-1";
        int min_length = INT_MAX;

        for(char ch : p) freq_map_p[ch]++;

        int l=0, r=0;
        int m=p.length(), n=s.length();
        int match_count = 0;

        while (r < n){
            // acquire
            while(r < n and match_count < m){
                char ch = s[r];
                freq_map[ch]++;
                if(freq_map[ch] <= freq_map_p[ch])
                    match_count++;
                r++;
            }

            // release
            while (l <= r and match_count == m){
                // int length = r-l+1;
                int length = r-l;
                if(length < min_length){
                    min_length = length;
                    res = s.substr(l, length);
                }

                char ch = s[l];
                freq_map[ch] = max(0, freq_map[ch]-1);
                if(freq_map[ch] < freq_map_p[ch])
                    match_count --;
                l++;
            }
        }
        return res;
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;

    }
    return 0;
}