#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int search(int arr[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // TODO
        int n = h-l+1;
        int pivot = 0;

        while (l <= h){
            int mid = (l+h)/2;

            // found min element
            if(arr[mid] < arr[(mid-1+n)%n])
            {
                pivot = mid;
                break;
            }

            // found max element
            if(arr[mid] > arr[(mid+1)%n])
            {
                pivot = (mid+1)%n;
                break;
            }
            if(arr[l] <= arr[mid])
                l = mid+1;
            else if(arr[mid] <= arr[h])
                h = mid-1;
        }

        if(not pivot) return binary_search(arr, 0, n-1, key);
        return binary_search(arr,0,pivot-1,key) + binary_search(arr,pivot,n-1,key) + 1;

    }

    // TODO
    int binary_search(int *arr, int low, int high, int key)
    {
        while (low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == key)
                return mid;
            if(arr[mid] < key)
                low = mid+1;
            else
                high = mid-1;
        }

        return -1;
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
