/*
    https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
    Tags:  Strings, Palindrome
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LongestPalindrome
{
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

    private static String solve(String s){
        // code here
        int n = s.length();
        for(int length=n; length>0; length--){
            for(int i=0; i<=n-length; i++){
                String substring = s.substring(i,i+length);
                if(isPalindrome(substring))
                    return substring;
            }
        }
        System.out.println(isPalindrome(s));
        return null;
    }

    private static boolean isPalindrome(String str){
        int n = str.length();
        for(int i=0; i<n/2; i++) {
            if (str.charAt(i) != str.charAt(n-i-1))
                return false;
        }
        return true;
    }
}
