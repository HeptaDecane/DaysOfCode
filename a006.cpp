#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    void rearrange(long long *arr, int n){
        // TODO
        int i_min = 0;
        int i_max = n-1;
        long long MAX = arr[i_max]+1;

        for(int i=0; i<n; i++){

            // at even index put maximum element
            if(i%2 == 0){
                arr[i] += (arr[i_max]%MAX)*MAX;
                i_max--;
            }
                // at even index put minimum element
            else {
                arr[i] += (arr[i_min]%MAX)*MAX;
                i_min++;
            }
        }

        for(int i=0; i<n; i++)
            arr[i] /= MAX;
    }
};


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

        Solution ob;

        //calling rearrange() function
        ob.rearrange(arr, n);

        //printing the elements
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
    return 0;
}