/*
    https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
    Tags: Stringsit
*/

import java.util.Scanner;
public class ReverseWords {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s = sc.next();
            System.out.println(solve(s));
            t--;
        }
    }

    //Function to reverse words in a given string.
    private static String solve(String str)
    {
        // code here
        String[] words = str.split("\\.");

        StringBuilder result = new StringBuilder();
        String separator = "";

        for(int i=words.length-1; i>=0; i--){
            result.append(separator);
            result.append(words[i]);
            separator = ".";
        }

        return result.toString();
    }
}
