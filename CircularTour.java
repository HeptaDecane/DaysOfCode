/*
https://practice.geeksforgeeks.org/problems/circular-tour/1
Tags: Misc
*/

import java.util.*;

public class CircularTour {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t =sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            sc.nextLine();
            String str = sc.nextLine();
            String arr[] = str.split(" ");
            int p[] = new int[n];
            int d[] = new int[n];
            int j=0;
            int k=0;
            for(int i=0; i<2*n; i++)
            {
                if(i%2 == 0)
                {
                    p[j]= Integer.parseInt(arr[i]);
                    j++;
                }
                else
                {
                    d[k] = Integer.parseInt(arr[i]);
                    k++;
                }
            }

            System.out.println(solve(p,d));
            t--;
        }
    }

    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    private static int solve(int[] petrol, int[] distance) {
        // Your code here
        int n = petrol.length;
        int start = 0;
        int petrolLeft = 0;

        for(int i=start; i<n;){
            petrolLeft = petrolLeft + petrol[i] - distance[i];
            i++;

            if(petrolLeft<0){
                for(; i<n; i++){
                    if(petrol[i]>=distance[i]){
                        start = i;
                        petrolLeft = 0;
                        break;
                    }
                }
            }
        }

        if(petrolLeft < 0) return -1;

        for(int i=0; i<start; i++){
            petrolLeft = petrolLeft + petrol[i] - distance[i];
            if(petrolLeft < 0) return -1;
        }

        return start;
    }
}