#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

// Position this line where user code will be pasted.

// Driver code
int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a;
        cin >> a;
        MinHeap h(a);
        for (ll i = 0; i < a; i++) {
            int c;
            int n;
            cin >> c;
            if (c == 1) {
                cin >> n;

                h.insertKey(n);
            }
            if (c == 2) {
                cin >> n;
                h.deleteKey(n);
            }
            if (c == 3) {
                cout << h.extractMin() << " ";
            }
        }
        cout << endl;
        // delete h.harr;
        h.harr = NULL;
    }
    return 0;
}



//Function to extract minimum value in heap and then to store
//next minimum value at first index.
int MinHeap::extractMin(){
    // TODO
    if(heap_size == 0) return -1;
    else if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    else {
        int min = harr[0];
        swap(harr[0], harr[heap_size-1]);
        heap_size--;
        MinHeapify(0);
        return min;
    }
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i){
    // TODO
    if(i>=heap_size or heap_size==0)
        return;

    decreaseKey(i, INT_MIN);
    extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k){
    // TODO
    if(heap_size < capacity){
        int i = heap_size;
        harr[i] = k;
        heap_size ++;

        // sift up
        while (i>0 and harr[parent(i)]>harr[i]){
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val){
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

//Function to swift down
void MinHeap::MinHeapify(int i){
    while (true){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i]) smallest = l;
        if (r < heap_size && harr[r] < harr[smallest]) smallest = r;

        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            i = smallest;
        } else break;
    }
}