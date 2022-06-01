#include<bits/stdc++.h>
using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
            int QueryType=0;
            cin>>QueryType;
            if(QueryType==1)
            {
                int a;
                cin>>a;
                sq->push(a);
            }else if(QueryType==2){
                cout<<sq->pop()<<" ";

            }
        }
        cout<<endl;
    }


}

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x){
    // TODO
    while(not s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(x);

    while(not s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    // TODO
    if(s1.empty()) return -1;
    int top = s1.top();
    s1.pop();
    return top;
}