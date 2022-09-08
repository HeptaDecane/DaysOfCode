#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // TODO
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }

        return count;
    }

    // TODO
    void bfs(int i, int j, vector<vector<char>> &grid){
        queue<pair<int,int>> q;

        grid[i][j] = 'v';   // mark visited
        q.push({i,j});

        while (not q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int di=-1; di<=1; di++){
                for(int dj=-1; dj<=1; dj++){
                    int dr = r+di;
                    int dc = c+dj;
                    if(isUnvisitedLand(dr, dc, grid)){
                        grid[dr][dc] = 'v';     // mark visited
                        q.push({dr,dc});
                    }
                }
            }
        }
    }

    // TODO
    bool isUnvisitedLand(int i, int j, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        return i>=0 and j>=0 and i<n and j<m and grid[i][j]=='1';
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
