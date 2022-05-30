#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        MyQueue *sq = new MyQueue();

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


//Function to push an element into the queue.
void MyQueue:: push(int x){
    // TODO
    auto *node = new QueueNode(x);
    if(front == nullptr){
        front = node;
        rear = node;
    }
    else{
        rear->next = node;
        rear = node;
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop(){
    // TODO
    if(front == nullptr) return -1;
    auto *node = front;
    int data = node->data;

    if(front == rear){
        front = nullptr;
        rear = nullptr;
    }
    else front = front->next;
    delete node;
    return data;
}
