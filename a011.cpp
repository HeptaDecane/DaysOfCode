#include <bits/stdc++.h>
using namespace std;


class Solution{

public:
    vector<int> leaders(int arr[], int n){
        // TODO
        vector<int> leaders;

        int max_right = arr[n-1];
        for(int i=n-1; i>=0; i--){
            if(max_right <= arr[i]){
                leaders.push_back(arr[i]);
                max_right = arr[i];
            }
        }

        reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};


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
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);

        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }

        cout << endl;

    }
}
