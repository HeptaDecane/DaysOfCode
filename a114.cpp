#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    bool are_same(int arr[]){
        int ref = 0;
        for(int i='a'; i<='z'; i++){
            if(arr[i] == 0) continue;
            ref = arr[i];
            break;
        }

        for(int i='a'; i<='z'; i++){
            if(arr[i] == 0) continue;
            if(arr[i] != ref) return false;
        }
        return true;
    }

    bool sameFreq(string s) {
        // TODO
        int freq_map[256] = {0};
        for (char ch : s)
            freq_map[ch]++;

        if(are_same(freq_map)) return true;

        for(int i='a'; i<='z'; i++){
            if(freq_map[i] == 0) continue;
            freq_map[i]--;
            if(are_same(freq_map))
                return true;
            freq_map[i]++;
        }
        return false;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}
