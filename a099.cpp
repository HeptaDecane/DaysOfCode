#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n){
        // TODO
        unordered_map<int,int> arr_map;
        for(int i=0; i<n; i++)
            arr_map[arr[i]]++;

        vector<pair<int,int>> freq_arr;
        for(int i=0; i<n; i++)
            freq_arr.push_back({arr[i], arr_map[arr[i]]});

        sort(freq_arr.begin(), freq_arr.end(), [](pair<int,int> a, pair<int,int> b){
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });

        vector<int> res;
        for(auto x : freq_arr)
            res.push_back(x.first);

        return res;
    }
};


int main() {


    int t;
    cin >> t;


    while(t--){


        int n;
        cin >> n;

        int a[n+1];

        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(a,n);
        for(int i:v)
            cout<<i<<" ";
        cout << endl;
    }

    return 0;
}
