#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // TODO
        sort(candies, candies+n);
        int min_cost=0, max_cost=0;
        int i, remaining;

        i = 0;
        remaining = n;
        while (remaining > 0){
            min_cost += candies[i];
            i++;
            remaining--;
            remaining -= k;
        }

        i=n-1;
        remaining = n;
        while (remaining > 0){
            max_cost += candies[i];
            i--;
            remaining--;
            remaining -= k;
        }

        return {min_cost, max_cost};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
