#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // TODO
        vector<pair<int,int>> meetings;
        for(int i=0; i<n; i++)
            meetings.push_back({start[i], end[i]});

        sort(meetings.begin(), meetings.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        });

        int count = 1;
        pair<int,int> meeting = meetings[0];
        for(int i=1; i<n; i++){
            if(meetings[i].first > meeting.second){
                count++;
                meeting = meetings[i];
            }
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
