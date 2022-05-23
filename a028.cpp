#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2){
        // TODO
        if(str1.length() != str2.length()) return false;
        int n = str1.length();

        bool clockwise = true, anticlockwise = true;
        for(int i=0; i<n; i++){
            if(str1[i] != str2[(i+2)%n]) clockwise = false;
            if(str1[(i+2)%n] != str2[i]) anticlockwise = false;
            if(!clockwise and !anticlockwise) return false;
        }

        return true;
    }

};

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string b;
        cin>>s>>b;
        Solution obj;
        cout<<obj.isRotated(s,b)<<endl;
    }
    return 0;
}