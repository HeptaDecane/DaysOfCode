#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // TODO

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));

        int longest_path = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                longest_path = max(longest_path, dfs(matrix, dp, i, j, INT_MIN));
        }
        return longest_path;
    }

    // TODO
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, int prev){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i<0 or j<0 or i==n or j==m) return 0;
        if(matrix[i][j] <= prev) return 0;

        if(dp[i][j] != 0) return dp[i][j];

        int path_length = 1;
        path_length = max(path_length, 1+ dfs(matrix, dp, i+1, j, matrix[i][j]));
        path_length = max(path_length, 1+ dfs(matrix, dp, i-1, j, matrix[i][j]));
        path_length = max(path_length, 1+ dfs(matrix, dp, i, j+1, matrix[i][j]));
        path_length = max(path_length, 1+ dfs(matrix, dp, i, j-1, matrix[i][j]));
        dp[i][j] = path_length;

        return path_length;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)cin >> matrix[i][j];
        Solution obj;
        int ans = obj.longestIncreasingPath(matrix);
        cout << ans <<"\n";
    }
    return 0;
}
