/*
    https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1
    Tags: Arrays, Sorting
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends




// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input array
// m, n: size of arrays X[] and Y[] respectively
long long countPairs(int arr1[], int arr2[], int m, int n)
{
    int zeros=0, ones=0, twos=0, threes=0, fours=0;
    for(int i=0; i<n; i++){
        switch (arr2[i]) {
            case 0:
                zeros++;
                break;
            case 1:
                ones++;
                break;
            case 2:
                twos++;
                break;
            case 3:
                threes++;
                break;
            case 4:
                fours++;
                break;
        }
    }

    sort(arr2,arr2+n);

    long long total = 0, count=0;
    for(int i=0; i<m; i++){
        count = 0;
        if(arr1[i] == 0)
            count += 0;
        else if (arr1[i] == 1)
            count += zeros;
        else{
            count = arr2 + n - upper_bound(arr2, arr2+n, arr1[i]);
            count += zeros + ones;
            if(arr1[i] == 2)
                count -= (threes + fours);
            if(arr1[i] == 3)
                count += twos;
        }

        total += count;
    }
    return total;

}


// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int M,N;
        cin>>M>>N;
        int i,a[M],b[N];
        for(i=0;i<M;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<N;i++)
        {
            cin>>b[i];
        }
        cout<<countPairs(a, b, M, N)<<endl;
    }
}  // } Driver Code Ends

/*
1 3 2
2 1 6
1 5

 */