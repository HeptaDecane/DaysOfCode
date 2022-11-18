#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minThrow(int k, int arr[]){
        // TODO
        int n=5, m=6;

        unordered_map<int,int> jumps;
        for(int i=0; i<k; i++){
            int start = arr[2*i];
            int end = arr[2*i+1];
            jumps[start] = end;
        }

        queue<pair<int,int>> q;
        unordered_set<int> visited;     // +1 for one-based indexed board

        int cell = 1;
        int moves = 0;
        visited.insert(cell);
        q.push({cell, moves});

        while (not q.empty()){
            cell = q.front().first;
            moves = q.front().second;
            q.pop();

            for(int i=0; i<=6; i++){
                int next_cell = cell + i;
                if(jumps.find(next_cell) != jumps.end())
                    next_cell = jumps[next_cell];

                if(next_cell == n * m) return moves + 1;

                if(visited.find(next_cell) == visited.end()){
                    visited.insert(next_cell);
                    q.push({next_cell, moves + 1});
                }
            }
        }

        return -1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
