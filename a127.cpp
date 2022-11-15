#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int isCircle(int n, vector<string> str_arr)
    {
        // TODO
        int v = 26;
        vector<int> adj[v];
        vector<int> ingress(v, 0);
        vector<int> egress(v, 0);

        for(string str : str_arr){
            int start = str[0] - 'a';
            int end = str[str.length()-1] - 'a';

            egress[start]++;
            ingress[end]++;
            adj[start].push_back(end);
        }

        // check ingress == egress
        for(int i=0; i<v; i++){
            if(ingress[i] != egress[i])
                return 0;
        }

        // if dfs traverse all the nodes in single run graph is connected
        int node = str_arr[0][0] - 'a';
        vector<bool> visited(v,false);
        dfs(node,adj,visited);

        for(int i=0; i<v; i++){
            if(not visited[i] and ingress[i]!=0) return 0;
        }

        return true;
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
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;

        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }

        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}