#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // TODO
        stack<long long> stack;
        vector<long long> res;

        for(int i=n-1; i>=0; i--){
            while (not stack.empty() and stack.top()<=arr[i])
                stack.pop();

            if(stack.empty()) res.push_back(-1);
            else res.push_back(stack.top());
            stack.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];

        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
    return 0;
}