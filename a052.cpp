#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

//Function to push an integer into the s.
void MyStack ::push(int x){
    // TODO
    auto *node = new StackNode(x);
    if(top != nullptr)
        node->next = top;
    top = node;

}

//Function to remove an item from top of the s.
int MyStack ::pop(){
    // TODO
    if(top == nullptr) return -1;

    auto *node = top;
    int data = node->data;

    top = top->next;

    delete node;
    return data;
}
