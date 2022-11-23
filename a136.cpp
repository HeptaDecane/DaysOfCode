#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string findLargest(int n, int s){
        // TODO

        if(s == 0)
            return n==1 ? "0" : "-1";

        if(s > 9*n) return "-1";

        string num = "";
        for(int i=0; i<n; i++){
            if(s >= 9){
                num.append("9");
                s = s-9;
            }
            else{
                num.append(to_string(s));
                s = 0;
            }
        }

        return num;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;

        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
