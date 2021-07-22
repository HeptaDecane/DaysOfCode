/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
Tags: Strings, Dynamic Programming
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FormPalindrome {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while(t-- > 0){
            String str = read.readLine();

            System.out.println(solve(str));
        }
    }

    private static int solve(String str) {
        int n = str.length();
        int[][] matrix = new int[n][n];

        for(int length=1; length<=n; length++){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;

                if(i==j)
                    matrix[i][j] = 1;
                else if(str.charAt(i) == str.charAt(j))
                    matrix[i][j] = matrix[i+1][j-1] +2;
                else
                    matrix[i][j] = Math.max(matrix[i][j-1],matrix[i+1][j]);
            }
        }

        return str.length()-matrix[0][n-1];
    }
}

/*

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 43

*/