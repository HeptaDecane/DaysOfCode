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
        vector<pair<int,int>> v;

        for(int i=0; i<nums.size(); i++)
            v.push_back({nums[i],i});

        sort(v.begin(), v.end());

        for(int i=0; i<nums.size(); i++){
            int j = v[i].second;

            if(i != j){
                swap(v[i], v[j]);
                swaps++;
                i--;
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
