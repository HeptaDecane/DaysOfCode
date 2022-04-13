#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int inversions = 0;

    void merge(long long arr[], long long low, long long mid, long long high){
        long long n1 = mid-low+1;
        long long n2 = high-mid;
        long long left[n1], right[n2];

        for(int i=0;i<n1;i++) left[i] = arr[low+i];
        for(int i=0;i<n2;i++) right[i] = arr[mid+1+i];

        long long i=0, j=0, index=low;

        while (i<n1 and j<n2){
            if(left[i] <= right[j]){
                arr[index] = left[i];
                i++;
            }
            else{
                inversions += n1-i;
                arr[index] = right[j];
                j++;
            }
            index++;
        }

        while(i<n1) arr[index++] = left[i++];
        while(j<n2) arr[index++] = right[j++];

    }

    void merge_sort(long long arr[], long long low, long long high){
        if(low<high){
            long long mid = low+(high-low)/2;
            merge_sort(arr,low,mid);
            merge_sort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }


    long long int inversionCount(long long arr[], long long n){
        // TODO
        merge_sort(arr,0,n-1);
        return inversions;
    }

};

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
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }

    return 0;
}