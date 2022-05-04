#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}


int findElement(int arr[], int n) {
    // TODO
    vector<int> left_max(n);
    vector<int> right_min(n);

    left_max[0] = arr[0];
    right_min[n-1] = arr[n-1];

    for(int i=1, j=n-2; i<n; i++, j--){
        left_max[i] = max(left_max[i-1], arr[i]);
        right_min[j] = min(right_min[j+1], arr[j]);
    }

    for(int i=1; i<=n-2; i++){
        if(left_max[i] == right_min[i])
            return arr[i];
    }

    return -1;
}