#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    long long countPairs(int arr_x[], int arr_y[], int m, int n){
        // TODO
        long long count = 0;
        sort(arr_y, arr_y+n);

        int map_y[5] = {0};

        for(int i=0; i<n; i++){
            int y = arr_y[i];
            if(y < 5)
                map_y[y]++;
        }

        for(int i=0; i<m; i++){
            int x = arr_x[i];

            // if x is 0, then there cannot be any value such that x^y > y^x
            if (x == 0) continue;

            // if x is 1, then the number of pairs is equal to number of zeroes in Y[]
            if (x == 1){
                count += map_y[0];
                continue;
            }

            // if x>1, increase number of pairs for y=0 and y=1
            count += (map_y[0] + map_y[1]);

            int upper_bound_x = upper_bound(arr_y, arr_y+n, x) - arr_y;
            int nos_gt_x = n - upper_bound_x;
            count += nos_gt_x;

            // decrease number of pairs for x=2 and (y=4 or y=3)
            if (x == 2)
                count -= (map_y[3] + map_y[4]);

            // increase number of pairs for x=3 and y=2
            if (x == 3)
                count += map_y[2];

        }
        return count;
    }
};



int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int M,N;
        cin>>M>>N;
        int i,a[M],b[N];
        for(i=0;i<M;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<N;i++)
        {
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.countPairs(a, b, M, N)<<endl;
    }
}