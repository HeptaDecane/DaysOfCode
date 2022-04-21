#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    int findPlatform(int arr[], int dep[], int n){
        // TODO
        vector<pair<int, int>> schedule(n);
        for(int i=0; i<n; i++)
            schedule[i] = {arr[i], dep[i]};

        // sort based on arrival time
        sort(schedule.begin(), schedule.end());

        priority_queue<int, vector<int>, greater<int>> q;
        int count = 1;
        q.push(schedule[0].second);

        for(int i=1; i<n; i++){
            if(q.top() >= schedule[i].first)
                count++;
            else
                q.pop();

            q.push(schedule[i].second);
        }

        return count;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    }
    return 0;
}