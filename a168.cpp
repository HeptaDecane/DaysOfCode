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
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // TODO
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
