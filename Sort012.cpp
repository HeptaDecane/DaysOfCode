/*
    https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
    Tags:  Arrays, 3-Way Partitioning, Sorting
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;


    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    // code here
    for(int i=0,j=0,k=n-1; j<=k;) {
        if (a[j] == 0) {
            swap(a[j], a[i]);
            i++;
            j++;
        } else if (a[j] == 1) {
            j++;
        } else if (a[j] == 2) {
            swap(a[j], a[k]);
            k--;
        }
    }
}