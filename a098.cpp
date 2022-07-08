#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> arr, int n, vector<int> ref, int m){
        // TODO
        map<int, int> arr_map;
        vector<int> sorted;

        // frequency map for arr
        for(int x : arr)
            arr_map[x]++;

        for(int x : ref){
            int count = arr_map[x];
            for(int i=0; i<count; i++)
                sorted.push_back(x);
            arr_map.erase(x);
        }

        for(auto x : arr_map){
            int count = x.second;
            for(int i=0; i<count; i++)
                sorted.push_back(x.first);
        }

        return sorted;
    }
};


int main(int argc, char *argv[])
{

    int t;

    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<int> a1(n);
        vector<int> a2(m);

        for(int i = 0;i<n;i++){
            cin >> a1[i];
        }

        for(int i = 0;i<m;i++){
            cin >> a2[i];
        }

        Solution ob;
        a1 = ob.sortA1ByA2(a1, n, a2, m);


        for (int i = 0; i < n; i++)
            cout<<a1[i]<<" ";

        cout << endl;


    }
    return 0;
}
