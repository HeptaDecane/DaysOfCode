/*
https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
Tags: Arrays, Hash, Searching
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class ArraySubset {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            StringTokenizer stt = new StringTokenizer(br.readLine());

            long n = Long.parseLong(stt.nextToken());
            long m = Long.parseLong(stt.nextToken());
            long a1[] = new long[(int)(n)];
            long a2[] = new long[(int)(m)];


            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a1[i] = Long.parseLong(inputLine[i]);
            }
            String inputLine1[] = br.readLine().trim().split(" ");
            for (int i = 0; i < m; i++) {
                a2[i] = Long.parseLong(inputLine1[i]);
            }

            System.out.println(solve( a1, a2, n, m));

        }
    }

    public static String solve(long[] a1, long[] a2, long n, long m) {
        Set<Long> set = new HashSet<>();

        for(long element : a1)
            set.add(element);

        for(long element : a2){
            if(!set.contains(element))
                return "No";
        }

        return "Yes";
    }
}