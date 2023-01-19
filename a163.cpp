#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int findOnce(int arr[], int n)
    {
        // TODO
        int low = 0;
        int high = n-2;

        while(low <= high){
            int mid = (low+high)/2;
            if((mid%2==0 and arr[mid]==arr[mid+1]) or (mid%2==1 and arr[mid]==arr[mid-1]))
                low = mid+1;
            else
                high = mid-1;
        }
        return arr[low];
    }
};


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }

        Solution ob;

        int res = ob.findOnce(A,n);
        cout << res << endl;
    }

    return 0;
}
