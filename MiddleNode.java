/*
https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
Tags: Linked List
*/

import java.util.*;
import java.io.*;

/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
*/

public class MiddleNode{
    static class Node{
        int data;
        Node next;

        Node(int x){
            data = x;
            next = null;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            for(int i=0; i<n-1; i++)
            {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }
            int ans = solve(head);
            System.out.println(ans);
            t--;
        }
    }

    private static int solve(Node head) {
        // Your code here.
        Node p,q;
        for(p=head, q=head; q!=null && q.next!=null; p=p.next, q=q.next.next);
        return p.data;
    }
}