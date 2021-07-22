/*
https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
Tags: Linked List
*/

import java.util.*;

/* node of linked list:

class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}

*/

public class RotateLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();

            int a = sc.nextInt();
            Node head = new Node(a);
            Node tail = head;

            for (int i=0; i<n-1; i++)
            {
                a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }

            int k = sc.nextInt();

            head = solve(head,k);
            printList(head);
        }
    }

    public static void printList(Node n) {
        while (n != null) {
            System.out.print(n.data + " ");
            n = n.next;
        }
        System.out.println();
    }

    //Function to rotate a linked list.
    private static Node solve(Node head, int k) {
        // add code here
        if (head==null) return null;

        int n = 0;
        Node last = head;
        for(Node p=head; p!=null; p=p.next) {
            last = p;
            n++;
        }

        last.next = head;
        k %= n;

        for(int i=0; i<k; i++)
            head = head.next;

        last = head;
        Node p = head;
        for(int i=0; i<n; i++){
            last = p;
            p = p.next;
        }
        last.next = null;

        return head;
    }
}