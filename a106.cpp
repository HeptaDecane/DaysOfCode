#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    // arr[] : the input array
    // N : size of the array arr[]
    int findLongestConseqSubseq(int arr[], int n){
        // TODO
        unordered_set<int> arr_set;
        for(int i=0; i<n; i++) arr_set.insert(arr[i]);

        int max_length = 0;
        for(int i=0; i<n; i++){
            // go to starting of sequence
            if(arr_set.find(arr[i]-1) != arr_set.end())
                continue;

            int curr_length = 0;
            int num = arr[i];
            while (arr_set.find(num) != arr_set.end()){
                num++;
                curr_length++;
            }

            max_length = max(max_length, curr_length);
        }

        return max_length;
    }
};


int main()
{
    int  t,n,i,a[100001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        Solution obj;
        cout<<obj.findLongestConseqSubseq(a, n)<<endl;
    }

    return 0;
}
