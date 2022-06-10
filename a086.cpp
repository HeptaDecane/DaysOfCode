#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // TODO
        vector<int> res;
        priority_queue<int,vector<int>,greater<>> q;

        for(int i=0; i<n; i++){
            q.push(arr[i]);
            if(q.size() < k)
                res.push_back(-1);
            else{
                if(q.size() > k)
                    q.pop();
                res.push_back(q.top());
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}