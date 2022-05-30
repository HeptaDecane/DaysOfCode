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


class Solution{
public:
    // TODO
    Node* reverse(Node *head){
        Node *prev = nullptr;
        Node *curr = head;
        Node *next;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(Node *head){
        // TODO
        if(head == nullptr or head->next==nullptr) return true;

        Node *slow_ptr = head;
        Node *fast_prt = head;
        Node *prev = nullptr;
        while(fast_prt!=nullptr and fast_prt->next!=nullptr){
            prev = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_prt = fast_prt->next->next;
        }
        prev->next = nullptr;

        Node *second_half;
        // even no. of nodes
        if(fast_prt == nullptr) second_half = slow_ptr;
        // odd no. of nodes
        else second_half = slow_ptr->next;

        Node *p = head;
        Node *q = reverse(second_half);

        while (p!=nullptr and q!=nullptr){
            if(p->data != q->data) return false;
            p = p->next;
            q = q->next;
        }

        return true;
    }
};

int main()
{
    int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}