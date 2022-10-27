#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the shortest distance of all the vertices from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src){
        // TODO
        vector<int> d(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, PairComparator> pq;

        d[src] = 0;
        pq.push({src, d[src]});

        while (not pq.empty()){
            int node = pq.top().first;
            int distance = pq.top().second;
            pq.pop();

            for(vector<int> node_pair : adj[node]){
                int next_node = node_pair[0];
                int next_distance = node_pair[1];
                if(d[next_node] > d[node]+next_distance){
                    d[next_node] = d[node]+next_distance;
                    pq.push({next_node,d[next_node]});
                }
            }
        }
        return d;
    }

    // TODO
    struct PairComparator{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second > b.second;
        }
    };

};



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
        int S;
        cin>>S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for(int i=0; i<V; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}
