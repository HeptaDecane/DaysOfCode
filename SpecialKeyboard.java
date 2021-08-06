/*
https://practice.geeksforgeeks.org/problems/special-keyboard3018/1
Tags: Dynamic Programming, Recursion
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SpecialKeyboard {
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            System.out.println(solve(N));
        }
    }

    private static int solve(int n){
        // code here
        if(n<7) return n;

        int[] dp = new int[n+1];
        for(int i=1; i<=6; i++)
            dp[i] = i;

        for(int i=7; i<=n; i++){
            for(int j=i-3,k=2; j>=1; j--,k++){
                int current = dp[j]*k;
                dp[i] = Math.max(dp[i],current);
            }
        }
        return dp[n];
    }
}