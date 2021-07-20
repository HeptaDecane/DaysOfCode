/*
https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
Tags: Strings
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class AnagramCheck {

    public static void main (String[] args)throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0)
        {
            String str = br.readLine();
            String s1 = str.split(" ")[0];
            String s2 = str.split(" ")[1];

            if(solve(s1,s2))
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
    }

    //Function is to check whether two strings are anagram of each other or not.
    public static boolean solve(String a,String b){
        // Your code here
        Map<Character,Integer> mapA = new HashMap<>();
        Map<Character,Integer> mapB = new HashMap<>();

        for(char ch : a.toCharArray()){
            if(mapA.containsKey(ch))
                mapA.put(ch, mapA.get(ch)+1);
            else
                mapA.put(ch, 1);
        }

        for(char ch : b.toCharArray()){
            if(mapB.containsKey(ch))
                mapB.put(ch, mapB.get(ch)+1);
            else
                mapB.put(ch, 1);
        }

        return mapA.equals(mapB);
    }
}


