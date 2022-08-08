#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    // Function to find majority element in the array
    // arr: input array
    // n: size of input array
    int majorityElement(int arr[], int n){
        // TODO
        unordered_map<int, int>freq_map;
        for(int i=0; i<n; i++) freq_map[arr[i]]++;

        for(auto pair : freq_map){
            if(pair.second > n/2)
                return pair.first;
        }
        return -1;
    }
};


int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];

        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
