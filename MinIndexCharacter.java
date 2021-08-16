/*
https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1
Tags: Hash, STL, Strings
*/

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MinIndexCharacter {
    public static void main (String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0)
        {
            t--;

            String s1=sc.next();
            String s2=sc.next();

            int res = solve(s1, s2);
            System.out.println(res);
        }
    }

    //Function to find the minimum indexed character.
    public static int solve(String str, String pattern) {
        // Your code here
        Map<Character,Integer> map = new HashMap<>();

        int i = 0;
        for(char ch : str.toCharArray()){
            if(!map.containsKey(ch))
                map.put(ch,i);
            i++;
        }

        int minIndex = Integer.MAX_VALUE;
        for(char ch : pattern.toCharArray()){
            Integer index = map.get(ch);
            if(index!=null)
                minIndex = Math.min(index,minIndex);
        }

        return minIndex==Integer.MAX_VALUE? -1 : minIndex;
    }
}
