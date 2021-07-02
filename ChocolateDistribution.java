/*
    https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
    Tags:  Arrays, Sorting
*/

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ChocolateDistribution
{
    public static void main (String[] args)
    {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0)
        {
            long n = sc.nextLong();
            ArrayList<Long> arr = new ArrayList<Long>();
            for(int i = 0;i<n;i++)
            {
                long x = sc.nextInt();
                arr.add(x);
            }
            long m = sc.nextLong();

            System.out.println(solve(arr,n,m));
        }

    }

    public static long solve(ArrayList<Long> a, long n, long m) {
        // your code here
        Collections.sort(a);
        long difference = Long.MAX_VALUE;

        for(int i=0; i+m-1<n; i++){
            if(difference > a.get(i+(int)m-1)-a.get(i))
                difference = a.get(i+(int)m-1)-a.get(i);
        }
        return difference;
    }
}
