/*
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
Tags: Arrays, Hash
*/

import java.util.*;

public class LargestZeroSum {

    // Returns length of the maximum length subarray with 0 sum

    // Drive method
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0)
        {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();

            System.out.println(solve(arr, n));
            T--;
        }
    }

    private static int solve(int[] arr, int n) {
        // Your code here
        Map<Integer,Integer> map = new HashMap<>();

        int sum = 0;
        int maxLength = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];

            if(arr[i]==0 && maxLength==0)
                maxLength = 1;
            if(sum == 0)
                maxLength = i+1;

            if(map.containsKey(sum))
                maxLength = Math.max(maxLength,i-map.get(sum));
            else
                map.put(sum,i);
        }
        return maxLength;
    }
}
