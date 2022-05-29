#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

    int t;
    cin>>t;
    while(t--){
        int n,m,flag=1,flag1=1;
        struct Node * temp=NULL;
        struct Node * head=NULL;
        struct Node * pre=NULL;
        struct Node * tempB=NULL;
        struct Node * preB=NULL;
        cin>>n;
        int work[n];
        for(int i=0;i<n;i++)
            cin>>work[i];
        for(int i=0;i<n;i++){
            m=work[i];
            --m;
            int data;
            scanf("%d",&data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if(flag){
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else{
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for(int j=0;j<m;j++){

                int temp_data;
                scanf("%d",&temp_data);
                tempB = new Node(temp_data);

                if(flag1){
                    temp->bottom=tempB;
                    preB=tempB;
                    flag1=0;
                }
                else{
                    preB->bottom=tempB;
                    preB=tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2=head;

        Node* root = flatten(head);
        printList(root);
        cout<<endl;

    }
    return 0;
}

// TODO
struct Comparator{
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};

Node *flatten(Node *root){
    // TODO
    if (root == nullptr) return root;
    priority_queue<Node*, vector<Node*>, Comparator> queue;

    Node *p = root;
    while (p != nullptr){
        queue.push(p);
        p = p->next;
    }

    Node *anchor = new Node(0);
    Node *end = anchor;

    while(not queue.empty()){
        Node* q = queue.top();
        queue.pop();

        end->bottom = q;
        end = end->bottom;

        if (q->bottom != nullptr)
            queue.push(q->bottom);
    }

    return anchor->bottom;
}
