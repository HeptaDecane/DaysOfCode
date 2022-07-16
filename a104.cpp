#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector <int> countDistinct (int arr[], int n, int k){
        // TODO
        vector<int> res;
        unordered_map<int,int> freq_map;

        int i=0, j=0;
        while (j<n){
            freq_map[arr[j]]++;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                res.push_back(freq_map.size());
                freq_map[arr[i]]--;
                if(freq_map[arr[i]] == 0)
                    freq_map.erase(arr[i]);
            }
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
