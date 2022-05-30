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

struct Node *start = NULL;


class Solution
{
public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // TODO
        Node *zeros_anchor = new Node(-1);
        Node *ones_anchor = new Node(-1);
        Node *twos_anchor = new Node(-1);

        Node *zeros = zeros_anchor;
        Node *ones = ones_anchor;
        Node *twos = twos_anchor;

        Node *p = head;
        while (p != nullptr){
            Node *next = p->next;

            if(p->data == 0){
                zeros->next = p;
                zeros = zeros->next;
                zeros->next = nullptr;
            }

            if(p->data == 1){
                ones->next = p;
                ones = ones->next;
                ones->next = nullptr;
            }

            if(p->data == 2){
                twos->next = p;
                twos = twos->next;
                twos->next = nullptr;
            }
            p = next;
        }

        if(twos_anchor->next != nullptr)
            ones->next = twos_anchor->next;
        if(ones_anchor->next != nullptr)
            zeros->next = ones_anchor->next;

        return zeros_anchor->next;
    }
};


void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
