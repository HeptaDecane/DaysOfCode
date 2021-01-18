/*
    https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1
    Tags: Sorting, Two-pointer-algorithm
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


//User function template for C++
class Solution{
public:

    int countTriplet(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
        int count = 0,sum;

        for(int i=0; i<n; i++){
            int low = 0;
            int high = n-1;
            while(low < high){
                sum = arr[low]+arr[high];

                if(arr[i] == sum){
                    if(i!=low and i!=high)
                        count++;
                    low++;
                    high--;
                }
                else if(arr[i] > sum)
                    low++;
                else if(arr[i] < sum)
                    high--;
            }
        }

        return count;
    }
};

// { Driver Code Starts.


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
}  // } Driver Code Ends