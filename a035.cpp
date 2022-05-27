#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;

        cin>>a;
        cin>>b;

        cout<<strstr(a,b)<<endl;
    }
}

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x){
    // TODO
    int n = s.length();
    int m = x.length();
    if(m > n) return -1;

    for(int i=0; i<n-m+1; i++){
        int j=0;
        while(j < m){
            if(s[i+j] != x[j])
                break;
            j++;
        }
        if(j == m) return i;
    }
    return -1;
}