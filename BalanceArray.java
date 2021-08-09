/*
https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1
Tags: Arrays, Hash
*/

import java.io.*;
import java.util.*;

public class BalanceArray {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            String line = br.readLine();
            String[] q = line.trim().split("\\s+");
            int n =Integer.parseInt(q[0]);
            int m =Integer.parseInt(q[1]);
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            long a[] = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(a1[i]);
            }
            String line2 = br.readLine();
            String[] a2 = line2.trim().split("\\s+");
            long b[] = new long[m];
            for (int i = 0; i < m; i++) {
                b[i] = Long.parseLong(a2[i]);
            }
            long ans = solve(a,n,b,m);
            System.out.println(ans);
        }
    }

    private static long solve(long[] array1, int n, long[] array2, int m) {
        // Your code goes here
        Set<Long> set = new HashSet<>();

        long sum1 = Arrays.stream(array1).sum();
        long sum2 = Arrays.stream(array2).sum();

        // sumA - a + b = sumB - b + a
        // 2a - 2b  = sumA - sumB
        // a - b  = (sumA - sumB) / 2

        if((sum1-sum2)%2 != 0) return -1;

        long target = (sum1-sum2)/2;

        for(long element : array2) set.add(element);

        for(long element : array1) {
            if (set.contains(element - target))
                return 1;
        }

        return -1;
    }
}

