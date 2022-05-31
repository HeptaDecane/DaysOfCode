#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
            int QueryType=0;
            cin>>QueryType;
            if(QueryType==1)
            {
                int a;
                cin>>a;
                qs->push(a);
            }else if(QueryType==2){
                cout<<qs->pop()<<" ";

            }
        }
        cout<<endl;
    }
}

//Function to push an element into stack using two queues.
void QueueStack :: push(int x){
    // TODO
    while(not q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }

    q1.push(x);

    while (not q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues.
int QueueStack :: pop(){
    // TODO
    if(q1.empty()) return -1;
    int front = q1.front();
    q1.pop();
    return front;
}
