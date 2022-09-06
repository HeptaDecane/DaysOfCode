#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // TODO
        vector<bool> visited(v, false);
        for(int i=0; i<v; i++){
            if(visited[i]) continue;
            if(traverseCycle(i,-1,v,adj,visited))
                return true;
        }
        return false;
    }

    // TODO
    bool traverseCycle(int node, int parent, int v, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        for(int vertex : adj[node]){
            if(not visited[vertex]){
                if(traverseCycle(vertex, node, v, adj, visited))
                    return true;
            }
            else if(vertex != parent)
                return true;
        }

        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}