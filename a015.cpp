#include<bits/stdc++.h>
using namespace std;


class Solution{

public:
    long long trappingWater(int arr[], int n){
        // TODO
        int left = 0, right = n-1;
        int left_max = 0, right_max = 0;
        long long water = 0;

        while (left <= right){
            if(right_max <= left_max){
                water += max(0, right_max-arr[right]);
                right_max = max(right_max, arr[right]);
                right--;
            }
            else {
                water += max(0, left_max-arr[left]);
                left_max = max(left_max, arr[left]);
                left++;
            }
        }
        return water;
    }
};


int main(){

    int t;
    //testcases
    cin >> t;

    while(t--){
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;

    }

    return 0;
}