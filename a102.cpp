#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // TODO
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target = k - (arr[i]+arr[j]);
                int left = j+1;
                int right = n-1;

                while (left < right){
                    int sum = arr[left]+arr[right];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else{
                        vector<int> quad(4);
                        quad[0] = arr[i];
                        quad[1] = arr[j];
                        quad[2] = arr[left];
                        quad[3] = arr[right];
                        res.push_back(quad);

                        while (left<right and quad[2]==arr[left]) left++;
                        while (left<right and quad[3]==arr[right]) right--;
                    }
                }
                while (j+1<n && arr[j+1]==arr[j]) j++;
            }
            while (i+1<n && arr[i+1]==arr[i]) i++;
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}