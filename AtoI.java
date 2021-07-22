/*
https://practice.geeksforgeeks.org/problems/implement-atoi/1
Tags: Strings, Design-Pattern
*/

import java.util.Scanner;

public class AtoI
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            String str = sc.nextLine();

            System.out.println(solve(str));
            t--;
        }
    }

    private static int solve(String str){
        // Your code here
        int result = 0;
        int sign = 1;
        for(char ch : str.toCharArray()){
            if(ch == '-' && sign == 1)
                sign = -1;
            else if(Character.isDigit(ch))
                result = result*10 + (ch-'0');
            else
                return -1;
        }
        return sign*result;
    }
}