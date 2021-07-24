/*
https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
Tags: Linked List
*/

import java.util.Scanner;

public class Sort012 {
    static class Node {
        int data;
        Node next;
        Node(int key)
        {
            data = key;
            next = null;
        }
    }

    public static void main (String[] args)
    {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            while(n-- > 1){
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }

            head = solve(head);
            printList(head);
            System.out.println();
        }
    }

    public static void printList(Node head)
    {
        if(head == null)
            return;

        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    //Function to sort a linked list of 0s, 1s and 2s.
    private static Node solve(Node head) {
        // add your code here
        Node zero = null;
        Node one = null;
        Node two = null;

        for(Node p=head; p!=null;){
            Node temp = p.next;
            switch (p.data){
                case 0:
                    p.next = zero;
                    zero = p;
                    break;
                case 1:
                    p.next = one;
                    one = p;
                    break;
                case 2:
                    p.next = two;
                    two = p;
                    break;
            }
            p = temp;
        }

        Node sorted = null;

        for(Node p=two; p!=null;){
            Node temp = p.next;
            p.next = sorted;
            sorted = p;
            p = temp;
        }

        for(Node p=one; p!=null;){
            Node temp = p.next;
            p.next = sorted;
            sorted = p;
            p = temp;
        }

        for(Node p=zero; p!=null;){
            Node temp = p.next;
            p.next = sorted;
            sorted = p;
            p = temp;
        }

        return sorted;
    }

}