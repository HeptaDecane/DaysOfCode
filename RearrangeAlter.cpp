/*
    https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1
    Tags: Arrays, Mathematics, Number Magic
*/

// { Driver Code Starts
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(long long *arr, int n)
{

    // Your code here
    int pMax = n-1, pMin = 0;
    int e8 = 1e8;
    // 1 <= arr[i] <= 1e7
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            arr[i] = arr[i] + (arr[pMax] % e8) * e8;
            pMax --;
        } else {
            arr[i] = arr[i] + (arr[pMin] % e8) * e8;
            pMin ++;
        }
    }

    for(int i=0; i<n; i++)
        arr[i] = arr[i]/e8;

}

// { Driver Code Starts.

// Driver program to test above function
int main()
{
    int t;

    //testcases
    cin >> t;

    while(t--){

        //size of array
        int n;
        cin >> n;

        long long arr[n];

        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }

        //calling rearrange() function
        rearrange(arr, n);

        //printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends