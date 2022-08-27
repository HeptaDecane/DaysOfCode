#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // TODO
        vector<int> res;
        vector<bool> visited(v, false);
        queue<int> q;

        int node = 0;
        visited[node] = true;
        q.push(node);
        while (not q.empty()){
            node = q.front();
            q.pop();
            res.push_back(node);
            visited[node] = true;
            for(int vertex: adj[node]){
                if(not visited[vertex]){
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }

        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
