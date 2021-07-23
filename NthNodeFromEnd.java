/*
https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
Tags: Linked List
*/

import java.util.*;

public class NthNodeFromEnd {
    static class Node {
        int data;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }
    Node head;
    Node tail;

    /* Function to print linked list */
    void printList(Node head)
    {
        Node temp = head;
        while (temp != null)
        {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }


    /* Inserts a new Node at front of the list. */
    public void addToTheLast(Node node)
    {

        if (head == null)
        {
            head = node;
            tail = node;
        } else
        {
            tail.next = node;
            tail = node;
        }
    }

    /* Drier program to test above functions */
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();

        while(t>0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            NthNodeFromEnd llist = new NthNodeFromEnd();
            //int n=Integer.parseInt(br.readLine());
            int a1=sc.nextInt();
            Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }

            //System.out.println(llist.head.data);
            //System.out.println(k);
            System.out.println(solve(llist.head,k));

            t--;
        }
    }

    //Function to find the data of nth node from the end of a linked list.
    private static int solve(Node head, int n) {
        // Your code here
        Node p=head;
        for(int i=0; i<n; i++){
            if(p == null) return -1;
            else p=p.next;
        }

        Node q;
        for(q=head; p!=null; p=p.next)
            q = q.next;

        return q.data;
    }
}
