/*
    https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
    Tags:  Arrays, Prefix-sum
*/

// { Driver Code Starts
#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        //calling equilibriumPoint() function
        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {

    // Your code here
    long long int rightSum = 0, leftSum = 0;
    for(int i=0; i<n; i++)
        rightSum += a[i];

    for(int i=0; i<n; i++){
        rightSum -= a[i];
        if(leftSum == rightSum)
            return i+1;
        leftSum += a[i];
    }
    return -1;

}