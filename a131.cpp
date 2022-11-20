#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // TODO
        vector<pair<int,int>> activities;
        for(int i=0; i<n; i++)
            activities.push_back({start[i], end[i]});

        sort(activities.begin(), activities.end(), [](pair<int,int> &a, pair<int,int> &b){
            return a.second < b.second;
        });

        int count=1;
        pair<int,int> activity = activities[0];

        for(int i=1; i<n; i++){
            if(activities[i].first > activity.second){
                count++;
                activity = activities[i];
            }
        }

        return count;
    }
};

int main()
{
    int t;

    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
