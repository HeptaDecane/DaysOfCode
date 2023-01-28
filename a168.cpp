#include <bits/stdc++.h>
using namespace std;


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // TODO
        int n1 = m-l+1;
        int n2 = r-m;

        int *arr1 = new int[n1];
        int *arr2 = new int[n2];

        for(int i=0, idx=l; i<n1; i++) arr1[i] = arr[idx++];
        for(int i=0, idx=m+1; i<n2; i++) arr2[i] = arr[idx++];

        int i=l, p=0, q=0;
        while (p<n1 and q<n2){
            if(arr1[p] < arr2[q]) arr[i++]=arr1[p++];
            else arr[i++]=arr2[q++];
        }

        while (p < n1) arr[i++]=arr1[p++];
        while (q < n2) arr[i++]=arr2[q++];

    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // TODO
        if(l >= r) return;

        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
};


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){

        scanf("%d",&n);
        int arr[n+1];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n-1);
        printArray(arr, n);
    }
    return 0;
}
