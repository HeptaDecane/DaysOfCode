#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


class Solution
{
public:

    // TODO
    Node* reverse(Node* head){
        Node *prev = nullptr;
        Node *curr = head;
        Node *next;

        while (curr != nullptr){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second){
        // TODO
        first = reverse(first);
        second = reverse(second);

        int carry = 0;
        Node *head = nullptr;
        Node *node = nullptr;
        while(first != nullptr or second != nullptr){

            if(first == nullptr){
                node = new Node((second->data + carry) % 10);
                carry = (second->data+carry)/10;
                second = second->next;
            }
            else if(second == nullptr){
                node = new Node((first->data + carry) % 10);
                carry = (first->data+carry)/10;
                first = first->next;
            }
            else {
                node = new Node((first->data + second->data + carry) % 10);
                carry = (first->data + second->data + carry)/10;
                first = first->next;
                second = second->next;
            }

            node->next = head;
            head = node;
        }

        if(carry != 0){
            node = new Node(carry);
            node->next = head;
            head = node;
        }

        return head;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}