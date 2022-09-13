#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int x, int y) {
        // TODO
        queue<vector<int>> q;

        if(isSafe(0,0,grid)){
            grid[0][0] = -1;
            q.push({0,0,1});
        }

        while(not q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            int steps = q.front()[2];
            q.pop();

            if(r==x and c==y) return steps-1;

            vector<pair<int,int>> deltas = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto d : deltas){
                int dr = r + d.first;
                int dc = c + d.second;

                if(isSafe(dr, dc, grid)){
                    grid[dr][dc] = -1;
                    q.push({dr,dc,steps+1});
                }
            }
        }
        return -1;

    }

    // TODO
    bool isSafe(int i, int j, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        return i>=0 and j>=0 and i<n and j<m and grid[i][j]==1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
