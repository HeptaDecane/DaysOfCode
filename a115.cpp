#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // TODO
        vector<int> res;
        vector<bool> visited(v, false);
        dfs(res, visited, 0, adj);
        return res;
    }

    // TODO
    void dfs(vector<int> &res, vector<bool> &visited, int node, vector<int> adj[]){
        res.push_back(node);
        visited[node] = true;
        for(int vertex : adj[node]){
            if(not visited[vertex])
                dfs(res, visited, vertex, adj);
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}