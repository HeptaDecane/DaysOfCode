/*
https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
Tags: Arrays, Hash
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class ConsecutiveSubsequence {
    // Driver Code
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{ st = new StringTokenizer(br.readLine()); } catch (IOException  e){ e.printStackTrace(); }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{ str = br.readLine(); } catch (IOException e) { e.printStackTrace(); }
            return str;
        }

        Integer nextInt(){
            return Integer.parseInt(next());
        }
    }

    public static void main(String args[])
    {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int t = sc.nextInt();

        while(t>0)
        {
            int n = sc.nextInt();
            int[] a = new int[n];

            for(int i=0; i<n; i++)
                a[i] = sc.nextInt();
            out.println(solve(a, n));
            t--;
        }
        out.flush();
    }

    // arr[] : the input array
    // n : size of the array arr[]

    //Function to return length of the longest subsequence of consecutive integers.
    private static int solve(int[] arr, int n) {
        // add your code here
        Set<Integer> set = new HashSet<>();

        for(int element : arr) set.add(element);

        int maxLength = 1;
        for(int element : arr){
            // if current is not the starting of subsequence then skip
            if(set.contains(element-1)) continue;

            int i = element;
            while (set.contains(i)) i++;

            maxLength = Math.max(maxLength, i-element);
        }

        return maxLength;
    }
}
