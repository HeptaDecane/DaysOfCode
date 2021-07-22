/*
https://practice.geeksforgeeks.org/problems/implement-strstr/1
Tags:  Strings, Design-Pattern, Pattern Searching
*/

import java.util.*;


public class StrContains {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            String line = sc.nextLine();
            String a = line.split(" ")[0];
            String b = line.split(" ")[1];

            System.out.println(solve(a,b));

            t--;
        }
    }

    //Function to locate the occurrence of the string x in the string s.
    private static int solve(String s, String x) {
        // Your code here
        int n = s.length();
        int m = x.length();

        for(int i=0; i<=n-m; i++){
            for(int p1=i, p2=0; p2<m; p1++, p2++){
                if(s.charAt(p1) != x.charAt(p2))
                    break;
                if(p2 == m-1)
                    return i;
            }
        }
        return -1;
    }
}
