/*
https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
Tags: Strings, Arrays
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LongestPrefix {
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int n = Integer.parseInt(read.readLine().trim());
            String[] arr = read.readLine().trim().split(" ");

            System.out.println(solve(arr, n));
        }
    }

    private static String solve(String[] arr, int n){
        // code here
        String longestPrefix = arr[0];
        for(String string : arr){
            if(string.length()<longestPrefix.length())
                longestPrefix = string;
        }

        for(String string : arr){
            StringBuilder stringBuilder = new StringBuilder();
            for(int i=0; i<longestPrefix.length(); i++){
                if(string.charAt(i) == longestPrefix.charAt(i))
                    stringBuilder.append(longestPrefix.charAt(i));
            }
            longestPrefix = stringBuilder.toString();
        }

        if(longestPrefix.length()>0)
            return longestPrefix;
        else return "-1";
    }
}

