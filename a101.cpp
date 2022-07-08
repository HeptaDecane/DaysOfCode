#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> common_element(vector<int>v1,vector<int>v2){
        // TODO
        unordered_map<int,int> freq_map;
        for(int x : v1)
            freq_map[x]++;

        vector<int> res;
        for(int x : v2){
            if(freq_map[x] > 0){
                res.push_back(x);
                freq_map[x]--;
            }
        }

        sort(res.begin(), res.end());   //nlog(n)
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;

    }
}