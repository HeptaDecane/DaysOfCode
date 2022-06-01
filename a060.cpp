#include <bits/stdc++.h>
using namespace std;

// TODO
class LRUCache{
private:
    struct Node{
        int key, val;
        Node *next;
        Node *prev;
        Node(int _key, int _val){
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node*> cache;
    int cap;

    void add_first(Node *node){
        Node *head_next = head->next;

        node->next = head_next;
        node->prev = head;
        head->next = node;
        head_next->prev = node;
    }

    void remove_node(Node *node){
        Node *node_next = node->next;
        Node *node_prev = node->prev;

        node_next->prev = node_prev;
        node_prev->next = node_next;
    }


public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap){
        // TODO
        this->cap = cap;
        head->next = tail;
        tail->prev = head;
    }

    //Function to return value corresponding to the key.
    int get(int key){
        // TODO
        if(cache.find(key) == cache.end()) return -1;

        Node *node = cache[key];
        remove_node(node);
        add_first(node);
        return node->val;
    }

    //Function for storing key-value pair.
    void set(int key, int value){
        // TODO
        if(cache.find(key) != cache.end()){
            Node *node = cache[key];
            cache.erase(key);
            remove_node(node);
            delete node;
        }
        if(cache.size() == cap){
            Node *last = tail->prev;
            cache.erase(last->key);
            remove_node(last);
            delete last;
        }
        Node *node = new Node(key, value);
        add_first(node);
        cache[key] = node;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}