/*
https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
Tags: Queue, Stack, STL
*/

import java.util.Scanner;
import java.util.Stack;

public class QueueWithStacks {
    public static void main(String args[])
    {
        //Taking input using class Scanner
        Scanner sc = new Scanner(System.in);

        //Taking input the number of testcases
        int t = sc.nextInt();
        while(t>0)
        {
            //Creating a new object of class StackQueue
            Queue g = new Queue();

            //Taking input the total number of Queries
            int q = sc.nextInt();
            while(q>0)
            {
                int QueryTyoe = sc.nextInt();

                //If QueryTyoe is 1 then
                //we call the Push method
                //of class StackQueue
                //else we call the Pop method
                if(QueryTyoe == 1)
                {
                    int a = sc.nextInt();
                    g.Push(a);
                }else
                if(QueryTyoe == 2)
                    System.out.print(g.Pop()+" ");
                q--;

            }
            System.out.println();
            t--;
        }
    }

    static class Queue
    {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        //Function to push an element in queue by using 2 stacks.
        public void Push(int x) {
            // Your code here
            while (!stack1.isEmpty())
                    stack2.push(stack1.pop());

                stack1.push(x);

                while(!stack2.isEmpty())
                    stack1.push(stack2.pop());
        }


        //Function to pop an element from queue by using 2 stacks.
        public int Pop() {
            // Your code here
            return stack1.isEmpty()? -1 : stack1.pop();
        }
    }
}
