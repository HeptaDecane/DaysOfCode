#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minJumps(int arr[], int n){
        // TODO
        if(n<=1) return 0;
        if(arr[0] == 0) return -1;

        int max_reach = arr[0];
        int steps_left = arr[0];
        int jumps = 1;

        for(int i=1; i<n; i++){
            if(i==n-1) return jumps;

            max_reach = max(max_reach, i+arr[i]);
            steps_left--;
            if(steps_left == 0){
                jumps++;
                steps_left = max_reach-i;
                if(steps_left<=0) return -1;
            }
        }

        return -1;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

