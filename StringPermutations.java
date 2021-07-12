/*
    https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
    Tags:  Strings, Recursion, Backtracking
*/

import java.util.*;
import java.lang.*;
import java.io.*;
public class StringPermutations
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String S = br.readLine().trim();
            List<String> ans = solve(S);
            for( int i = 0; i < ans.size(); i++)
            {
                System.out.print(ans.get(i)+" ");
            }
            System.out.println();

        }
    }

    private static List<String> solve(String str) {
        // Code here
        char[] charStr = str.toCharArray();
        List<String> permutations = new ArrayList<>();
        permute(permutations, charStr, 0,charStr.length-1);
        Collections.sort(permutations);
        return permutations;
    }

    private static void permute(List<String> permutations, char[] str, int l, int r){
        //System.out.println(l+" "+r+" "+new String(str));
        if(l==r)
            permutations.add(new String(str));
        else
            for(int i=l; i<=r; i++){
                swap(str,l,i);
                permute(permutations, str, l+1, r);
                swap(str,l,i);
            }
    }

    private static void swap(char[] arr, int i, int j){
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
