/*
    https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
    Tags: Arrays, Prefix-sum, Searching, Sliding-window
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s){

    // Your code here
    vector<int> result;
    int sum = 0, start=0;

    for(int i=0; i<=n; i++){
        while(sum > s){
            sum = sum - arr[start];
            start++;
        }

        if(sum == s){
            result.push_back(start+1);
            result.push_back(i);
            return result;
        }

        sum = sum + arr[i];

    }

    result.push_back(-1);
    return result;

}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        vector<int>res;
        res = subarraySum(arr, n, s);

        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;

    }
    return 0;
}  // } Driver Code Ends


/*
function subarraySum (arr, sum) {
  let currentSum = arr[0]
  let start = 0;
  let end = 0
  for(let i = 1; currentSum !== sum; i++) {
    currentSum = currentSum + arr[i]
    end++;
    if(currentSum > sum) {
      currentSum =  currentSum - arr[start]
      start++
    }
  }
  console.log(start)
  console.log(end)
}
 */