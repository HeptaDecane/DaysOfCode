/*
    https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
    Tags:  Arrays, Dynamic Programming, Kadane's Algorithm
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){

    // Your code here
    int localMax = 0;
    int globalMax = INT_MIN;

    for(int i=0; i<n; i++){
        localMax = max(arr[i], localMax+arr[i]);
        globalMax = max(localMax, globalMax);
    }
    return globalMax;
}

// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends