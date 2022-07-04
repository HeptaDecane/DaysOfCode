#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int josephus(int n, int k){
        // TODO
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i] = i+1;
        k = k-1;
        josephus(arr, 0, k);
        return arr[0];
    }

    // TODO
    void josephus(vector<int> &arr, int idx, int k){
        if(arr.size() == 1) return;

        idx = (idx+k) % arr.size();
        arr.erase(arr.begin() + idx);
        josephus(arr, idx, k);
    }
};


int main() {

    int t;
    cin >> t;//testcases
    while (t--) {
        int n, k;
        cin >> n >> k;//taking input n and k

        //calling josephus() function
        Solution ob;
        cout << ob.josephus(n, k) << endl;
    }
    return 0;
}