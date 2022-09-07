#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int v, vector<int> adj[]){
        // TODO
        vector<bool> visited(v, false);
        vector<int> res;

        for(int i=0; i<v; i++){
            if(not visited[i])
                dfs(i, adj, visited, res);
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // TODO
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &res){
        visited[node] = true;

        for(int vertex : adj[node]){
            if(not visited[vertex])
                dfs(vertex, adj, visited, res);
        }
        res.push_back(node);
    }
};

int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
