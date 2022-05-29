#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;

    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }

    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


class Solution
{
public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        // TODO
        if(head == nullptr) return;

        Node* slow_ptr = head;
        Node* fast_ptr = head;
        Node* prev = nullptr;

        while (fast_ptr!=nullptr and fast_ptr->next!=nullptr){
            prev = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if(slow_ptr == fast_ptr) break;
        }

        // loop does not exist
        if(slow_ptr != fast_ptr) return;

        Node *p = head;
        Node *q = slow_ptr;
        while (p != q){
            prev = q;
            p = p->next;
            q = q->next;
        }

        // prev will point to the end of loop
        prev->next = nullptr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;

        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);

        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin>> pos;
        loopHere(head,tail,pos);

        Solution ob;
        ob.removeLoop(head);

        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
    return 0;
}