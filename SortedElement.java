/*
    https://practice.geeksforgeeks.org/problems/unsorted-array4925/1
    Tags:  Arrays, Dynamic Programming
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SortedElement {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while(t-- > 0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[] a = new int[n];
            String[] inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(inputLine[i]);
            }

            System.out.println(solve(a, n));

        }
    }

    private static int solve(int []arr, int n){
        int []leftMax = new int[n];
        int []rightMin = new int[n];

        leftMax[0] = arr[0];
        rightMin[n-1] = arr[n-1];
        for(int i=1,j=n-2; i<n; i++,j--){
            leftMax[i] = Math.max(leftMax[i-1],arr[i]);
            rightMin[j] = Math.min(rightMin[j+1],arr[j]);
        }

        for(int i=1; i<=n-2; i++){
            if(leftMax[i] == rightMin[i])
                return arr[i];
        }
        return -1;
    }
}
