#include <bits/stdc++.h>
using namespace std;

class Solution{
    int min_element;
    stack<int> s;
public:

    /*returns min element from s*/
    int getMin(){
        // TODO
        return s.empty() ? -1 : min_element;
    }

    /*returns popped element from s*/
    int pop(){
        // TODO
        if(s.empty()) return -1;

        if(s.top() < min_element){
            int top = min_element;
            min_element = min_element - s.top();
            s.pop();
            return top;
        }
        else {
            int top = s.top();
            s.pop();
            return top;
        }
    }

    /*push element x into the s*/
    void push(int x){
        // TODO
        if(s.empty()){
            min_element = x;
            s.push(x);
            return;
        }

        if(x < min_element) {
            s.push(x - min_element);
            min_element = x;
        }
        else s.push(x);
    }
};

int main()
{
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
            int qt;
            cin>>qt;
            if(qt==1)
            {
                //push
                int att;
                cin>>att;
                ob.push(att);
            }
            else if(qt==2)
            {
                //pop
                cout<<ob.pop()<<" ";
            }
            else if(qt==3)
            {
                //getMin
                cout<<ob.getMin()<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}