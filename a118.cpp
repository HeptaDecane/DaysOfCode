#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // TODO
        vector<bool> visited(v, false);
        vector<bool> walked(v, false);

        for(int i=0; i<v; i++){
            if(visited[i]) continue;
            if(traverseCycle(i, adj, visited, walked))
                return true;
        }
        return false;
    }

    // TODO
    bool traverseCycle(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &walked){
        visited[node] = true;
        walked[node] = true;

        for(int vertex : adj[node]){
            if(not visited[vertex]){
                if(traverseCycle(vertex, adj, visited, walked))
                    return true;
            }
            else if(walked[vertex])
                return true;
        }
        walked[node] = false;

        return false;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
