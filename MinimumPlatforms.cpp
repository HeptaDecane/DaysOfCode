/*
    https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
    Tags: Arrays, Greedy
*/

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);

    int platformCount = 1, result= 1;
    for(int i=1,j=0; i<n and j<n; ){
        if(arr[i] <= dep[j]){
            platformCount++;
            i++;
        } else if(arr[i] > dep[j]){
            platformCount--;
            j++;
        }
        result = max(platformCount,result);
    }
    return result;
}


// { Driver Code Starts.
// Driver code
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
        cout <<findPlatform(arr, dep, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends