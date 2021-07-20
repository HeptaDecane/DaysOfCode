/*
https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1
Tags: Strings
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedHashSet;
import java.util.Set;

public class RemoveDuplicates {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();

            String result = solve(s);

            System.out.println(result);
        }
    }

    private static String solve(String s){
        // code here
        Set<Character> charSet = new LinkedHashSet<>();

        for(char ch : s.toCharArray())
            charSet.add(ch);

        StringBuilder result = new StringBuilder();
        for(char ch : charSet)
            result.append(ch);

        return result.toString();
    }

}