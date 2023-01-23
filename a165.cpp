#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int binarysearch(int arr[], int n, int key) {
        // TODO
        int low = 0;
        int high = n-1;

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

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

