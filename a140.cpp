#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // TODO
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<bool> visited(v,false);

        int sum = 0;
        // {w, node}
        pq.push({0,0});

        while (not pq.empty()){
            auto it = pq.top();
            pq.pop();

            int w = it.first;
            int node = it.second;

            if(visited[node]) continue;
            visited[node] = true;
            sum += w;

            for(auto x : adj[node]){
                int adj_node = x[0];
                int edg_wt = x[1];

                if(not visited[adj_node])
                    pq.push({edg_wt, adj_node});
            }
        }

        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
