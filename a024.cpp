#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to reverse words in a given string.
    string reverseWords(string s){
        // TODO
        vector<string> words;
        string word;

        s.append(".");
        for(char ch : s){
            if(ch == '.'){
                words.push_back(word);
                word = "";
            }
            else word += ch;
        }

        string s_rev;
        for(int i=words.size()-1; i>=0; i--) {
            s_rev.append(words[i]);
            if(i != 0)
                s_rev.append(".");
        }

        return s_rev;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}