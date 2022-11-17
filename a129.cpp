#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string findOrder(string dict[], int n, int k) {
        // TODO
        vector<int> adj[k];

        for(int i=0; i<n-1; i++){
            string str1 = dict[i];
            string str2 = dict[i+1];

            int len = min(str1.length(),str2.length());
            for(int j=0; j<len; j++){
                if(str1[j] != str2[j]){
                    int start = str1[j] - 'a';
                    int end = str2[j] - 'a';
                    adj[start].push_back(end);
                    break;
                }
            }
        }

        string order;
        for(int vertex : topoSort(k, adj))
            order += char(vertex+'a');

        return order;
    }

    // TODO
    vector<int> topoSort(int v, vector<int> adj[]){
        // TODO
        vector<int> ingress(v, 0);
        vector<int> res;

        for(int i=0; i<v; i++){
            for(int vertex : adj[i])
                ingress[vertex]++;
        }

        queue<int> q;
        for(int i=0; i<v; i++){
            if(ingress[i] == 0)
                q.push(i);
        }

        while (not q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int vertex : adj[node]){
                ingress[vertex]--;
                if(ingress[vertex] == 0)
                    q.push(vertex);
            }
        }

        return res;
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
