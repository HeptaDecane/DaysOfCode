#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;

    cin>>val;
    head = tail = new Node(val);

    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

class Solution{
public:
    Node* findIntersection(Node* head1, Node* head2){
        // TODO
        if(head1 == nullptr or head2 == nullptr) return nullptr;

        Node *p = head1;
        Node *q = head2;
        unordered_map<int,bool> data_map;

        while(q != nullptr){
            data_map[q->data] = true;
            q = q->next;
        }

        Node *anchor = new Node(0);
        Node *tail = anchor;
        while (p != nullptr){
            int data = p->data;
            if(data_map[data]){
                tail->next = new Node(data);
                tail = tail->next;
            }
            p = p->next;
        }

        return anchor->next;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;

        cin>> n;
        Node* head1 = inputList(n);

        cin>>m;
        Node* head2 = inputList(m);
        Solution obj;
        Node* result = obj.findIntersection(head1, head2);

        printList(result);
        cout<< endl;
    }
    return 0;
}