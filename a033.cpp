#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

int longestSubstrDistinctChars (string s){
    // TODO
    unordered_map<char,int> char_map;
    int max_length = 0;

    int i=0;
    for(int j=0; j<s.length(); j++){
        // window_size = j-i+1
        char_map[s[j]]++;

        if(char_map.size() < j-i+1){
            while (char_map.size() < j-i+1){
                char_map[s[i]]--;
                if(char_map[s[i]] == 0)
                    char_map.erase(s[i]);
                i++;
            }
        }

        if(char_map.size() == j-i+1)
            max_length = max(max_length, j-i+1);
    }
    return max_length;
}