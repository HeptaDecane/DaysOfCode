#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        // TODO
        int map_a[256] = {0};
        int map_b[256] = {0};

        for(char ch : a) map_a[int(ch)] += 1;
        for(char ch : b) map_b[int(ch)] += 1;

        for(int i=0; i<256; i++){
            if(map_a[i] != map_b[i])
                return false;
        }
        return true;
    }

};

int main() {

    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}