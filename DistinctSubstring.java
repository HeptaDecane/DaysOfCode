/*
https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
Tags: Strings
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class DistinctSubstring {
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S = read.readLine();

            System.out.println(solve(S));
        }
    }

    private static int solve(String str){
        // code here
        Map<Character, Integer> map = new HashMap<>();

        int start = 0;
        int maxLength = 0;
        for(int i=0; i<str.length(); i++){
            if(map.containsKey(str.charAt(i)))
                start = Math.max(start, map.get(str.charAt(i)) + 1);

            map.put(str.charAt(i),i);
            maxLength = Math.max(maxLength, i-start+1);
        }

        return maxLength;
    }
}