#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    string chooseandswap(string a){
        // TODO
        vector<int> char_map(26,-1);

        for(int i=0; i<a.length(); i++){
            char ch = a[i];
            if(char_map[ch-'a'] == -1)
                char_map[ch-'a'] = i;
        }

        for(int i=0; i<a.length(); i++){
            char ch = find_smallest(char_map, a[i], i);
            if(ch != '\0'){
                swap_char(a, a[i], ch);
                break;
            }
        }

        return a;
    }

    // TODO
    // find smallest character after idx
    char find_smallest(vector<int>& char_map, char ch, int idx){
        for(int i=0; i<ch-'a'; i++){
            if(char_map[i] > idx)
                return char(i+'a');
        }
        return '\0';
    }

    // TODO
    void swap_char(string &str, char a, char b){
        for(char& ch : str){
            if(ch == a) ch=b;
            else if(ch == b) ch=a;
        }
    }

};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}

