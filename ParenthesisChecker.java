/*
https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
Tags: Stack, STL, Strings
*/

import java.util.Scanner;
import java.util.Stack;

public class ParenthesisChecker {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        //Reading total number of testcases
        int t= sc.nextInt();

        while(t-- >0)
        {
            //reading the string
            String st = sc.next();

            //calling ispar method of Paranthesis class
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(solve(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");

        }
    }

    //Function to check if brackets are balanced or not.
    private static boolean solve(String x) {
        // add your code here
        Stack<Character> stack = new Stack<>();

        for (char ch : x.toCharArray()){
            if((ch==')' || ch==']' || ch=='}') && stack.isEmpty())
                return false;

            if(ch=='(' || ch=='[' || ch=='{')
                stack.push(ch);

            else if(ch==')' && stack.peek()=='(')
                stack.pop();

            else if(ch==']' && stack.peek()=='[')
                stack.pop();

            else if(ch=='}' && stack.peek()=='{')
                stack.pop();

            else return false;

        }
        return stack.isEmpty();
    }
}