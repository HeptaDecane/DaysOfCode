/*
https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1
Tags: Strings, Recursion
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RecursiveStringClean {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
        while(t-->0){
            String S = br.readLine();
            System.out.println(solve(S));
        }
    }

    private static String solve(String s) {
        // code here
        String replaced = recursion(s,(char)0);
        return replaced;
//        while (true){
//            if(replaced.equals(s))
//                return s;
//            else {
//                System.out.println(replaced);
//                s = replaced;
//                replaced = recursion(s,(char)0);
//            }
//        }
    }

    private static String recursion(String str, char lastRemoved){
        if (str.length()==0)
            return str;

        if(str.charAt(0) == lastRemoved){
            lastRemoved = str.charAt(0);
            return recursion(str.substring(1),lastRemoved);
        }
        else if(str.length()>1 && str.charAt(0)==str.charAt(1)){
            lastRemoved = str.charAt(0);
            return recursion(str.substring(1),lastRemoved);
        }
        else
            return str.substring(0,1) + recursion(str.substring(1),(char)0);
    }
}

