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
        vector<vector<int>> dp(n, vector(m,-1));
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
