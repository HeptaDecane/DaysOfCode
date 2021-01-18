/*
    https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
    Tags: Arrays, Sorting
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


void merge(int arr1[], int arr2[], int n, int m)
{
    // code here
    for(int i=n-1, j=0; i>=0 and j<m; i--, j++){
        if(arr1[i]>arr2[j])
            swap(arr1[i],arr2[j]);
        else
            break;
    }
    sort(arr1,arr1+n);
    sort(arr2, arr2+m);
}


// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while(T--){
        int n, m;
        cin >> n >> m;

        int arr1[n], arr2[m];

        for(int i = 0;i<n;i++){
            cin >> arr1[i];
        }

        for(int i = 0;i<m;i++){
            cin >> arr2[i];
        }

        merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);


        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);

        cout<<endl;
    }

    return 0;
}
// } Driver Code Ends