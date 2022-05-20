#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalin (string s) {
        // TODO
        string longest_palindrome, palindrome;

        for(int i=0; i<s.length(); i++){
            // odd palindromes
            palindrome = palindrome_at_center(s, i, i);
            if (palindrome.length() > longest_palindrome.length())
                longest_palindrome = palindrome;

            // even palindromes
            palindrome = palindrome_at_center(s, i, i+1);
            if (palindrome.length() > longest_palindrome.length())
                longest_palindrome = palindrome;
        }

        return longest_palindrome;

    }

    // TODO
    string palindrome_at_center(string s, int start, int end){

        while (start >=0  and end < s.length()){
            if(s[start] == s[end])
                start--, end++;
            else break;
        }

        // undo last change to start, end
        start++, end--;
        return s.substr(start, end-start+1);
    }

};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}