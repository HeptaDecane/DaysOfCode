#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> combinations;

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        // TODO
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> candidates(s.begin(), s.end());
        sort(candidates.begin(), candidates.end());

        vector<int> store;
        combinationSum(candidates, target, 0, store);
        return combinations;
    }

    // TODO
    void combinationSum(vector<int> &candidates, int target, int idx, vector<int> &store){
        if(idx >= candidates.size()) return;

        if(target == 0){
            combinations.push_back(store);
            return;
        }

        // pick candidates[idx]
        if(candidates[idx] <= target){
            store.push_back(candidates[idx]);
            combinationSum(candidates, target-candidates[idx], idx, store);
            store.pop_back();
        }

        // don't pick candidates[idx]
        combinationSum(candidates, target, idx+1, store);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0) {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++) {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}