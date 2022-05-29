#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

Node* sortedMerge(Node* head1, Node* head2){
    // TODO
    Node *p = head1;
    Node *q = head2;

    if(p == nullptr) return q;
    if(q == nullptr) return p;

    if(p->data > q->data) swap(p, q);
    Node *root = p;

    while (p != nullptr and q != nullptr){
        Node *prev = nullptr;
        while (p != nullptr and p->data <= q->data){
            prev = p;
            p = p->next;
        }

        prev->next = q;
        swap(p, q);
    }

    return root;
}