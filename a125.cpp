#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid)
    {
        // TODO
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    break;
                }
            }
            if(not q.empty()) break;
        }

        while (not q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<pair<int,int>> deltas = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto d : deltas){
                int dr = r + d.first;
                int dc = c + d.second;

                if(is_safe(dr,dc,grid) and grid[dr][dc]==2)
                    return true;

                if(is_safe(dr,dc,grid) and grid[dr][dc]==3){
                    grid[dr][dc] = 1;
                    q.push({dr,dc});
                }
            }
        }

        return false;
    }

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
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
}
