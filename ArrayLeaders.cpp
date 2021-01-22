/*
    https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
    Tags:  Arrays, Searching
*/

// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




vector<int> leaders(int a[], int n){
    // code here
    int rightMax = INT_MIN;
    vector<int> result;
    for(int i=n-1; i>=0; i--){
        if(a[i]>=rightMax){
            result.push_back(a[i]);
            rightMax = a[i];
        }
    }

    if(result.empty())
        result.push_back(-1);

    reverse(result.begin(),result.end());
    return result;
}

// { Driver Code Starts.

int main()
{
    long long t;
    cin >> t;//testcases
    while (t--)
    {
        long long n;
        cin >> n;//total size of array

        int a[n];

        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }

        //calling leaders() function
        vector<int> v = leaders(a, n);

        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }

        cout << endl;

    }
}
// } Driver Code Ends