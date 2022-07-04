#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinations;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> store;
        combinationSum2(candidates, target, 0, store);
        return combinations;
    }

    void combinationSum2(vector<int> &candidates, int target, int idx, vector<int> &store){
        if(target == 0){
            combinations.push_back(store);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(candidates[idx] > target) break;
            if(i>idx and candidates[i]==candidates[i-1]) continue;

            store.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], i+1, store);
            store.pop_back();
        }

    }
};