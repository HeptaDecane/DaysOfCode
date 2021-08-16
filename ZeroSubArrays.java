/*
https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
Tags: Arrays, Hash
*/

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ZeroSubArrays {
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        sc.nextLine();
        while(t-->0)
        {
            int n;
            n=sc.nextInt();

            long[] arr = new long[n];


            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextLong();
            }
            System.out.println(solve(arr,n));
        }

    }

    //Function to count subarrays with sum equal to 0.
    private static long solve(long[] arr ,int n) {
        //Your code here
        Map<Long,Integer> map = new HashMap<>();
        map.put(0L,1);

        long sum = 0L;
        int count = 0;

        for(long element : arr){
            sum = sum + element;
            if(map.containsKey(sum)){
                count += map.get(sum);
                map.put(sum, map.get(sum)+1);
            }
            else map.put(sum,1);

        }
        return count;
    }
}