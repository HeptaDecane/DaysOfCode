#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // TODO
        queue<pair<int,int>> queue;
        int r = grid.size();
        int c = grid[0].size();

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 2)
                    queue.push({i, j});
            }
        }

        int time = 0;
        while(not queue.empty()){
            int n = queue.size();
            bool new_rots = false;
            while (n--){
                auto curr = queue.front();
                int i = curr.first;
                int j = curr.second;
                queue.pop();

                if(i-1>=0 and grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    queue.push({i-1, j});
                    new_rots = true;
                }
                if(i+1<r and grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    queue.push({i+1, j});
                    new_rots = true;
                }
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    queue.push({i, j-1});
                    new_rots = true;
                }
                if(j+1<c and grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    queue.push({i, j+1});
                    new_rots = true;
                }
            }
            if(new_rots) time++;
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
