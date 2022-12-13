#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> minPartition(int target)
    {
        // TODO
        vector<int> notes = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> res;

        int i=9;
        while(i >= 0){
            if(target >= notes[i]){
                target -= notes[i];
                res.push_back(notes[i]);
            }
            else i--;
        }

        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}