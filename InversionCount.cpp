/*
    https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
    Tags: Arrays, Merge Sort
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long int merge(long long arr[], long long low, long long high){
    long long inversionCount = 0;
    long long mid = (low+high)/2 ,i, j, k;
    long long temp[high-low+1];

    i = low;
    j = mid+1;
    k = 0;
    while((i<=mid) and (j<=high)){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        } else {
            temp[k] = arr[j];
            j++;
            k++;
            inversionCount = inversionCount + (mid+1-i);
        }
    }

    while (i <= mid ) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i=low,j=0; i <= high; i++,j++)
        arr[i] = temp[j];

    return inversionCount;
}

long long int mergeSort(long long arr[], long long low, long long high){
    long long inversionCount = 0;
    if(low < high){
        long long mid = (low + high)/2;

        inversionCount += mergeSort(arr, low, mid);
        inversionCount += mergeSort(arr, mid+1, high);
        inversionCount += merge(arr, low, high);
    }
    return inversionCount;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr,0,N-1);

}




// { Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while(T--){
        long long N;
        cin >> N;

        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }

        cout << inversionCount(A,N) << endl;
    }

    return 0;
}
// } Driver Code Ends
