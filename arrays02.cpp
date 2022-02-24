#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    int countTriplet(int arr[], int n){
        // TODO
        sort(arr, arr+n);

        int count = 0;
        for(int k=0; k<n; k++){
            int target = arr[k];

            int i=0, j=k-1;
            while (i < j){
                if(arr[i]+arr[j] < target)
                    i++;
                else if (arr[i]+arr[j] > target)
                    j--;
                else
                    count++, i++, j--;
            }
        }
        return count;
    }
};


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}