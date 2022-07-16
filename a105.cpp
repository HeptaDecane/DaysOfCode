#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        // TODO
        unordered_map<int,int> mod_map;
        for(int num : nums)
            mod_map[num%k]++;

        for(auto e : mod_map){
            int key = e.first;
            int a = e.second;
            int b = mod_map[k-key];

            if(key==0 and a%2==0) continue;
            if(a != b) return false;
        }
        return true;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}