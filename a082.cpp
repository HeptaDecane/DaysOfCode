#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // TODO
    void sift_down(int arr[], int i, int end){
        while(true){
            int left = 2*i+1;
            int right = 2*i+2;

            if(left<=end and right <=end){
                if(arr[i] >= max(arr[left], arr[right]))
                    break;
                else{
                    if(arr[left] > arr[right]){
                        swap(arr[i], arr[left]);
                        i = left;
                    }
                    else{
                        swap(arr[i], arr[right]);
                        i = right;
                    }
                }
            }

            else if(left <= end){
                if(arr[i] >= arr[left])
                    break;
                else{
                    swap(arr[i], arr[left]);
                    i = left;
                }
            }

            else if(right <= end){
                if(arr[i] >= arr[right])
                    break;
                else{
                    swap(arr[i], arr[right]);
                    i = right;
                }
            }

            else break;
        }
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n){
        // TODO

        // build heap
        for(int i=n-1; i>=0; i--)
            sift_down(arr, i, n-1);

        // sort
        for(int i=n-1; i>=0; i--){
            swap(arr[0],arr[i]);
            sift_down(arr, 0, i-1);
        }
    }
};


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        Solution ob;
        ob.heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}