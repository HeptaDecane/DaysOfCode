#include <bits/stdc++.h>
using namespace std;


class Solution{
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<>> min_heap;
    // max_heap:[1,2,3,4] | min_heap:[5,6,7,8]
public:
    // TODO
    void insertHeap(int &x){
        max_heap.push(x);
        balanceHeaps();
    }

    // TODO
    void balanceHeaps(){
        min_heap.push(max_heap.top());
        max_heap.pop();

        if(max_heap.size() < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    // TODO
    double getMedian(){
        if(max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top())/2;
        else
            return max_heap.top();
    }
};

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
        Solution ob;
        cin >> n;
        for(int i = 1;i<= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}