/*
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
Tags: Misc
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedHashMap;
import java.util.Map;

public class FirstNonRepeatingCharacter{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String A = br.readLine().trim();
            String ans = solve(A);
            System.out.println(ans);
        }
    }

    public static String solve(String str) {
        // code here
        Map<Character,Integer> map = new LinkedHashMap<>();
        StringBuilder result = new StringBuilder();
        for(char ch : str.toCharArray()){

            if(map.containsKey(ch))
                map.put(ch,map.get(ch)+1);
            else
                map.put(ch,1);

            char output = '#';
            for(char key : map.keySet()){
                if(map.get(key) == 1) {
                    output = key;
                    break;
                }
            }
            result.append(output);
        }
        return result.toString();
    }
}
