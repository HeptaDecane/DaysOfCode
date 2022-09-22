#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid){
        // TODO
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> d(n, vector<int>(m,INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;

        d[0][0] = grid[0][0];
        pq.push({0,0,d[0][0]});

        while (not pq.empty()){
            auto top = pq.top();
            int r = top[0];
            int c = top[1];
            int distance = top[2];
            pq.pop();

            vector<pair<int,int>> deltas = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto delta : deltas){
                int next_r = r + delta.first;
                int next_c = c + delta.second;
                if(not is_safe(next_r,next_c,grid)) continue;

                int next_distance = grid[next_r][next_c];
                if(d[next_r][next_c] > d[r][c]+next_distance){
                    d[next_r][next_c] = d[r][c]+next_distance;
                    pq.push({next_r, next_c, next_distance});
                }
            }
        }
        return d[n-1][m-1];
    }

    // TODO
    struct Comparator{
        bool operator()(vector<int> a, vector<int> b){
            return a[2] > b[2];
        }
    };

    // TODO
    bool is_safe(int i, int j, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        return i>=0 and j>=0 and i<n and j<m;
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
