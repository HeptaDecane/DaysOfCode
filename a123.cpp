#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<int> adj[]){
        // TODO

        // topological sort
        vector<bool> visited(v, false);
        stack<int> stk;
        for(int i=0; i<v; i++){
            if(not visited[i])
                dfs(i, adj, visited, stk);
        }

        // transpose graph
        vector<int> adj_t[v];
        for(int i=0; i<v; i++){
            for(int vertex : adj[i]){
                adj_t[vertex].push_back(i);
            }
        }

        // dfs on transpose in topological order
        int components = 0;
        visited = vector<bool>(v, false);

        while(not stk.empty()){
            int node = stk.top();
            stk.pop();

            if(not visited[node]){
                components++;
                dfs(node, adj_t, visited);
            }
        }

        return components;
    }

    // TODO
    void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &stk){
        visited[node] = true;

        for(int vertex : adj[node]){
            if(not visited[vertex])
                dfs(vertex, adj, visited, stk);
        }
        stk.push(node);
    }

    // TODO
    void dfs(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        for(int vertex : adj[node]){
            if(not visited[vertex])
                dfs(vertex, adj, visited);
        }
    }
};



int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
