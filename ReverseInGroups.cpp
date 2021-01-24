/*
    https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1
    Tags: Arrays
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





//User function template for C++

class Solution{
public:
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here

        int left, right;
        for(int i=0; i<n; i+=k){
            left = i;
            right = min(i+k-1, n-1);
            while(left < right){
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr;
        int k;
        cin >> k;

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for(long long i = 0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends