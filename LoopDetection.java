/*
https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
Tags: Linked List
*/

import java.util.Scanner;


class GFG
{
    static class Node {
        int data;
        Node next;

        Node(int x) {
            data = x;
            next = null;
        }
    }

    public static void makeLoop(Node head, Node tail, int x){
        if (x == 0) return;

        Node curr = head;
        for(int i=1; i<x; i++)
            curr = curr.next;

        tail.next = curr;
    }

    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t--> 0)
        {
            int n = sc.nextInt();

            int num = sc.nextInt();
            Node head = new Node(num);
            Node tail = head;

            for(int i=0; i<n-1; i++)
            {
                num = sc.nextInt();
                tail.next = new Node(num);
                tail = tail.next;
            }

            int pos = sc.nextInt();
            makeLoop(head, tail, pos);

            if(solve(head) )
                System.out.println("True");
            else
                System.out.println("False");
        }
    }

    //Function to check if the linked list has a loop.
    private static boolean solve(Node head){
        // Add code here
        for(Node p=head, q=head.next; q!=null && q.next!=null; p=p.next, q=q.next.next){
            if(p==q)
                return true;
        }
        return false;
    }
}
