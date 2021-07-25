/*
https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
Tags: Stack
*/

import java.util.*;

public class GetMinStack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T>0)
        {
            int q = sc.nextInt();
            CustomStack g = new CustomStack();
            while(q>0)
            {
                int qt = sc.nextInt();

                if(qt == 1)
                {
                    int att = sc.nextInt();
                    g.push(att);
                    //System.out.println(att);
                }
                else if(qt == 2)
                {
                    System.out.print(g.pop()+" ");
                }
                else if(qt == 3)
                {
                    System.out.print(g.getMin()+" ");
                }

                q--;
            }
            System.out.println();
            T--;
        }
    }

    static class CustomStack {
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> minStack = new Stack<>();

        /*returns min element from stack*/
        int getMin() {
            // Your code here
            return minStack.isEmpty() ? -1 : minStack.peek();
        }

        /*returns popped element from stack*/
        int pop() {
            // Your code here
            if(stack.isEmpty())
                return -1;
            minStack.pop();
            return stack.pop();
        }

        /*push element x into the stack*/
        void push(int x) {
            // Your code here
            stack.push(x);
            int min;
            min = (minStack.isEmpty() || x<minStack.peek()) ? x : minStack.peek();
            minStack.push(min);
        }
    }

}
