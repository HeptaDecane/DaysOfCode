/*
https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
Tags: Queue, Stack, STL
*/

import java.util.*;

public class StackWithQueues {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            Stack g = new Stack();

            int q = sc.nextInt();
            while(q>0)
            {
                int QueryType = sc.nextInt();
                if(QueryType == 1)
                {
                    int a = sc.nextInt();
                    g.push(a);
                }
                else if(QueryType == 2)
                    System.out.print(g.pop()+" ");
                q--;
            }
            System.out.println();



            t--;
        }
    }

    static class Stack {
        Queue<Integer> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>();

        //Function to push an element into stack using two queues.
        void push(int a) {
            // Your code here
            while (!queue1.isEmpty())
                queue2.add(queue1.remove());

            queue1.add(a);

            while (!queue2.isEmpty())
                queue1.add(queue2.remove());
        }

        //Function to pop an element from stack using two queues.
        int pop() {
            // Your code here
            return queue1.isEmpty()? -1 : queue1.remove();
        }
    }

}

