#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // TODO
        int swaps = 0;
        vector<int> refs(nums.begin(), nums.end());
        sort(refs.begin(), refs.end());

        unordered_map<int,int> index_map;
        for(int i=0; i<nums.size(); i++)
            index_map[nums[i]] = i;

        for(int i=0; i<nums.size(); i++){
            if(refs[i] != nums[i]){
                int j = index_map[refs[i]];
                index_map[nums[i]] = j;
                index_map[refs[i]] = i;
                swap(nums[i], nums[j]);
                swaps++;
            }
        }
        return swaps;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans <<"\n";
    }
    return 0;
}
