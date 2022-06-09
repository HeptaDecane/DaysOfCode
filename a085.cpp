#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

// TODO
struct NodeComparator{
    bool operator()(Node* first, Node* second){
        return first->data > second->data;
    }
};


class Solution{
public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k){
        // TODO
        priority_queue<Node*,vector<Node*>,NodeComparator> q;

        for(int i=0; i<k; i++)
            q.push(arr[i]);

        Node *anchor = new Node(INT_MIN);
        Node *tail = anchor;

        while (not q.empty()){
            Node *node = q.top();
            q.pop();
            tail->next = node;
            tail = tail->next;

            if(node->next)
                q.push(node->next);

            tail->next = nullptr;
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
        int N;
        cin>>N;
        struct Node *arr[N];
        for(int j=0;j<N;j++)
        {
            int n;
            cin>>n;

            int x;
            cin>>x;
            arr[j]=new Node(x);
            Node *curr = arr[j];
            n--;

            for(int i=0;i<n;i++)
            {
                cin>>x;
                Node *temp = new Node(x);
                curr->next =temp;
                curr=temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr,N);
        printList(res);

    }

    return 0;
}