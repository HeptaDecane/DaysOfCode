#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minJumps(int arr[], int n){
        // TODO
        int max_reach = 0;
        int steps_left = 0;
        int jumps = 0;

        for(int i=0; i<n; i++){
            if(i==n-1) return jumps;
            max_reach = max(max_reach, i+arr[i]);

            if(steps_left == 0){
                jumps++;
                steps_left = max_reach-i;
                if(steps_left<=0) return -1;
            }

            steps_left--;
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

