#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool ispar(string x){
        // TODO
        stack<int> stack;

        for(char ch : x){
            if(ch=='(' or ch=='[' or ch=='{')
                stack.push(ch);
            else{
                if(stack.empty()) return false;
                if(ch==')' and stack.top()!='(') return false;
                if(ch==']' and stack.top()!='[') return false;
                if(ch=='}' and stack.top()!='{') return false;

                stack.pop();
            }
        }
        return stack.empty();
    }

};

int main()
{
    int t;
    string a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        Solution obj;
        if(obj.ispar(a))
            cout<<"balanced"<<endl;
        else
            cout<<"not balanced"<<endl;
    }
}
