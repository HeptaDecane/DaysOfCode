#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // TODO
        vector<int> cache;
        int faults = 0;

        for(int i=0; i<n; i++){
            int page = pages[i];

            auto it = find(cache.begin(), cache.end(), page);

            if(it == cache.end()){
                faults++;

                if(cache.size() == c)
                    cache.erase(cache.begin());

                cache.push_back(page);
            }
            else{
                cache.erase(it);
                cache.push_back(page);
            }
        }

        return faults;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;

        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
