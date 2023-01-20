#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // TODO
        int n = h-l+1;
        int mid;

        while (l <= h){
            mid = (l+h)/2;
            if(arr[(mid+1)%n]>arr[mid] and arr[mid]<arr[(mid-1+n)%n])
                break;
            if(arr[l] <= arr[mid])
                l = mid+1;
            else
                h = mid-1;
        }

        int idx = -1;
        idx = binarySearch(arr,0,mid-1,key);
        if(idx != -1) return idx;

        idx = -1;
        idx = binarySearch(arr,mid,n-1,key);
        if(idx != -1) return idx;
    }

    // TODO
    int binarySearch(int *arr, int low, int high, int key)
    {
        if (high < low)
            return -1;

        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;

        if (key > arr[mid])
            return binarySearch(arr, (mid + 1), high, key);

        return binarySearch(arr, low, (mid - 1), key);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
}
