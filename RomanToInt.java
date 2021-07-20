/*
https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
Tags: Strings
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class RomanToInt {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String roman = br.readLine().trim();
            System.out.println(solve(roman));
        }
    }

    // Finds decimal value of a given roman numeral
    private static int solve(String str) {
        // code here
        Map<Character,Integer> map = new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);

        int sum = 0;
        char[] chars = str.toCharArray();
        int n = str.length();
        for(int i=0; i<n; i++){
                if(i<n-1 && map.get(chars[i]) < map.get(chars[i+1])){
                    sum += map.get(chars[i+1])-map.get(chars[i]);
                    i++;
                }
                else sum += map.get(chars[i]);
        }
        return sum;
    }

}