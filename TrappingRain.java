/*
    https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
    Tags:  Arrays, Dynamic Programming
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TrappingRain {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
        while(t-->0){

            //size of array
            int n = Integer.parseInt(br.readLine().trim());
            int arr[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");

            //adding elements to the array
            for(int i=0; i<n; i++){
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            //calling trappingWater() function
            System.out.println(solve(arr, n));
        }
    }

    private static int solve(int arr[], int n) {

        // Your code here
        int water = 0;
        int temp = 0;

        int leftWall = arr[0];
        int leftWallIndex = 0;

        for(int i=1; i<n; i++){
            if(arr[i] >= leftWall){
                leftWall = arr[i];
                leftWallIndex = i;
                temp = 0;
            }
            else {
                water += leftWall-arr[i];
                temp += leftWall-arr[i];
            }
        }

        if(leftWallIndex != n-1){
            water -= temp;
            int rightWall = arr[n-1];

            for(int i=n-1; i>=leftWallIndex; i--){
                if(arr[i] >= rightWall)
                    rightWall = arr[i];
                else
                    water += rightWall-arr[i];
            }
        }

        return water;
    }
}

