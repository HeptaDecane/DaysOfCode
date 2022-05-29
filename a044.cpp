#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int getNthFromLast(struct Node* head, int n);

int main()
{
    int T,i,n,l,k;

    cin>>T;

    while(T--){
        struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}


//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n){
    // TODO
    if(head == nullptr) return -1;

    Node *p = head, *q = head;
    for(int i=0; i<n; i++){
        if(q == nullptr) return -1;
        q = q->next;
    }

    while (q != nullptr){
        p = p->next;
        q = q->next;
    }

    return p->data;
}

