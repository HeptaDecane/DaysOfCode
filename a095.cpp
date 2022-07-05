#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<string> res;
    vector<string> findPath(vector<vector<int>> &map, int n) {
        // TODO
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if(map[0][0] == 1) findPath(0,0,n,map,visited,"");
        return res;

    }

    void findPath(int i, int j, int n, vector<vector<int>> &map, vector<vector<bool>> &visited, string move){
        if(i==n-1 and j==n-1){
            res.push_back(move);
            return;
        }

        visited[i][j] = true;

        // DOWN
        if(i+1<n and !visited[i+1][j] and map[i+1][j])
            findPath(i+1, j, n, map, visited, move+"D");

        // LEFT
        if(j-1>=0 and !visited[i][j-1] and map[i][j-1])
            findPath(i, j-1, n, map, visited, move+"L");

        // RIGHT
        if(j+1<n and !visited[i][j+1] and map[i][j+1])
            findPath(i, j+1, n, map, visited, move+"R");

        // UP
        if(i-1>=0 and !visited[i-1][j] and map[i-1][j])
            findPath(i-1, j, n, map, visited, move+"U");

        visited[i][j] = false;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}