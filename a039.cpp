#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution
{
public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k){
        // TODO
        if (head == nullptr) return head;

        Node* node = head;
        Node* tail = nullptr;
        while (node != nullptr) {
            tail = node;
            node = node->next;
        }
        tail->next = head;

        Node* prev = nullptr;
        for(int i=0; i<k; i++){
            prev = head;
            head = head->next;
        }
        prev->next = nullptr;
        return head;
    }
};


void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;

        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;

        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin>> k;

        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}