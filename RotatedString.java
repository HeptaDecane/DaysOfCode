/*
https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1
Tags: Strings
*/

import java.util.Scanner;

public class RotatedString {

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        String s12 = sc.nextLine();
        for(int i=0; i<t; i++){
            String s1 = sc.nextLine();
            String s2 = sc.nextLine();

            boolean flag = solve(s1, s2);

            if(flag == true) System.out.println("1");
            else System.out.println("0");

        }
    }

    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    private static boolean solve(String str1, String str2){
        // Your code here
        int n = str1.length();
        if(n<2) return str2.equals(str1);
        String leftRotated = str1.substring(2,n)+str1.substring(0,2);
        String rightRotated = str1.substring(n-2,n)+str1.substring(0,n-2);
        return str2.equals(leftRotated) || str2.equals(rightRotated);
    }
}
