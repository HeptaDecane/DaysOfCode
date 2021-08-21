/*
https://practice.geeksforgeeks.org/problems/uncommon-characters4932/1
Tags: Hash, Strings
*/

import java.io.*;
import java.util.*;

public class UncommonCharacters {
    public static void main(String[] args)throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            String A = sc.next();
            String B = sc.next();
            System.out.println(solve(A, B));
        }
    }

    private static String solve(String str1, String str2) {
        // code here

        Map<Character,Boolean> map1 = new HashMap<>();
        Map<Character,Boolean> map2 = new HashMap<>();

        for(char ch : str1.toCharArray())
            map1.put(ch,true);

        for(char ch : str2.toCharArray())
            map2.put(ch,true);

        String alphabets = "abcdefghijklmnopqrstuvwxyz";
        StringBuilder result = new StringBuilder();
        for(char ch : alphabets.toCharArray()){
            if(!map1.containsKey(ch) && !map2.containsKey(ch)) continue;
            if(!map1.containsKey(ch) || !map2.containsKey(ch))
                result.append(ch);
        }

        return result.length()==0 ? "-1" : result.toString();
    }
}