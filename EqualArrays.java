/*
https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1
Tags: Arrays, Hash, Sorting
*/

import java.util.*;
class GFG {
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);

        long t=sc.nextLong();

        while(t-->0)
        {
            int n=sc.nextInt();
            long[] arr=new long[n];
            long[] brr=new long[n];

            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextLong();
            }

            for(int i=0;i<n;i++)
                brr[i]=sc.nextLong();

            System.out.println(solve(arr, brr, n) ?"1":"0");

        }
    }

    //Function to check if two arrays are equal or not.
    private static boolean solve(long[] array1,long[] array2,int n) {
        //Your code here
        Map<Long,Integer> map1 = new HashMap<>();
        Map<Long,Integer> map2 = new HashMap<>();

        for(long key : array1)
            map1.merge(key, 1, Integer::sum);

        for(long key : array2)
            map2.merge(key, 1, Integer::sum);

        return map1.equals(map2);

    }

}
