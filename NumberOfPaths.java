/*
https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
Tags: Mathematical, Dynamic Programming, Recursion
*/

import java.lang.*;
import java.io.*;

public class NumberOfPaths {

    public static void main (String[] args) throws IOException  {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0){
            String[] inputLine = br.readLine().trim().split(" ");
            int m = Integer.parseInt(inputLine[0]);
            int n = Integer.parseInt(inputLine[1]);
            System.out.println(solve(m, n));
        }
    }

    private static long solve(int m, int n) {
        // Code Here
        long[][] paths = new long[m][n];

        for(int i=0; i<m; i++) paths[i][0] = 1;
        for(int i=0; i<n; i++) paths[0][i] = 1;

        for(int i=1; i<m; i++) {
            for (int j = 1; j < n; j++)
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
        }

        return paths[m-1][n-1];
        // (m+n-2)! / (n-1)!(m-1)!
    }
}
