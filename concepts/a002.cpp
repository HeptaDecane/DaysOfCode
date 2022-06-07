#include "bits/stdc++.h"
using namespace std;

void sift_down(int *arr, int i, int end){
    while(true){
        int left = 2*i+1;
        int right = 2*i+2;
        if(max(left,right) <= end){
            if(arr[i] >= max(arr[left], arr[right]))
                break;
            else if(arr[left] > arr[right]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else {
                swap(arr[i], arr[right]);
                i = right;
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


void print_array(int *a, int n){
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    int arr[] = {5, 2, 14, 3, 9, 7, 0, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"array: \n";
    print_array(arr, n);

    cout<<"build heap: \n";
    for(int i=n-1; i>=0; i--){
        sift_down(arr,i,n-1);
        print_array(arr,n);
    }

    cout<<"sort: \n";
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        sift_down(arr,0,i-1);
        print_array(arr,n);
    }

    return 0;
}