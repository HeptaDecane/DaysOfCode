#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    /*
        The function takes an array of heights, width and
        length as its 3 arguments where each index i value
        determines the height, width, length of the ith box.
        Here n is the total no of boxes.
    */
    int maxHeight(int height[],int width[],int length[],int n)
    {
        // TODO
        vector<Box> boxes;

        for(int i=0; i<n; i++){
            Box box;

            box.height = height[i];
            box.length = min(width[i],length[i]);
            box.width = max(width[i],length[i]);
            boxes.push_back(box);

            box.height = width[i];
            box.length = min(height[i],length[i]);
            box.width = max(height[i],length[i]);
            boxes.push_back(box);

            box.height = length[i];
            box.length = min(width[i],height[i]);
            box.width = max(width[i],height[i]);
            boxes.push_back(box);
        }

        n = 3*n;
        sort(boxes.begin(), boxes.end(), [](Box &a, Box &b){
            return a.length>b.length and a.width*b.width;
        });

        vector<int> dp(n);
        for(int i=0; i<n; i++) dp[i] = boxes[i].height;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(boxes[j].length>boxes[i].length and boxes[j].width>boxes[i].width)
                    dp[i] = max(dp[i], dp[j]+boxes[i].height);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

    struct Box{
        int length;
        int width;
        int height;
    };
};


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;


        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }

    return 0;
}

