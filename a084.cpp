#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string rearrangeString(string str){
        // TODO
        int char_map[256] = {0};

        for(char ch : str)
            char_map[ch]++;

        int start=0;
        for(int i=0; i<256; i++) {
            while (char_map[i]) {
                str[start] = char(i);
                char_map[i]--;
                start += 2;
                if (start >= str.length())
                    start = 1;
            }
        }

        for(int i=1; i<str.length()-1; i++){
            if(str[i] == str[i-1] or str[i] == str[i+1])
                return "-1";
        }
        return str;
    }

};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        string str1=ob.rearrangeString(str);
        int flag=1;
        int c[26] = {0};
        for(int i=0; i<str.length(); i++)
            c[str[i]-'a']+=1;
        int f = 0;
        int x = (str.length()+1)/2;
        for(int i=0; i<26; i++)
        {
            if(c[i]>x)
                f = 1;
        }
        if(f)
        {
            if(str1=="-1")
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
        else
        {
            int a[26] = {0};
            int b[26] = {0};
            for(int i=0; i<str.length(); i++)
                a[str[i]-'a']+=1;
            for(int i=0; i<str1.length(); i++)
                b[str1[i]-'a']+=1;

            for(int i=0; i<26; i++)
                if(a[i]!=b[i])
                    flag = 0;

            for(int i=0;i<str1.length();i++)
            {
                if(i>0)
                    if(str1[i-1]==str1[i])
                        flag=0;
            }
            if(flag==1)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}