#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.

    int minimumCostPath(vector<vector<int>>& grid){
        // TODO
        #define triplet pair<int,pair<int,int>>

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d(n, vector<int>(m,INT_MAX));
        priority_queue<triplet,vector<triplet>,greater<>>pq;

        d[0][0] = grid[0][0];
        pq.push({d[0][0],{0,0}});

        while (not pq.empty()){
            triplet top = pq.top();
            int distance = top.first;

            auto node = top.second;
            int r = node.first;
            int c = node.second;
            pq.pop();

            vector<pair<int,int>> deltas = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto delta : deltas){
                int next_r = r + delta.first;
                int next_c = c + delta.second;
                if(next_r<0 or next_c<0 or next_r>=n or next_c>=m) continue;
                int next_distance = grid[next_r][next_c];

                if(d[next_r][next_c] > d[r][c]+next_distance){
                    d[next_r][next_c] = d[r][c]+next_distance;
                    pq.push({d[next_r][next_c],{next_r, next_c}});
                }
            }
        }
        return d[n-1][m-1];
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<vector<int>>grid(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
}
