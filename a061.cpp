#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

/*You are required to complete this method*/
class Solution{
public:

    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
        // TODO
        int start = 0;
        int balance = 0;
        int required = 0;
        for(int i=0; i<n; i++){
            balance += p[i].petrol - p[i].distance;
            if(balance <0){
                required += balance;
                balance = 0;
                start = i+1;
            }
        }
        return balance+required >= 0 ? start : -1;
    }
};

/*
    // another solution
    int tour(petrolPump p[],int n){
        // TODO
        int start = 0;
        int curr = 0;
        int visits = 0;

        while (visits < 2*n){
            curr = start;
            int balance = 0;
            do{
                visits ++;
                balance += p[curr].petrol - p[curr].distance;
                if(balance < 0){
                    start = (curr+1)%n;
                    break;
                }
                else curr = (curr+1)%n;
            } while (start != curr);

            if(start == curr) return start;
        }
        return -1;
    }
*/

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}