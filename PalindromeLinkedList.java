/*
https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
Tags: Linked List, Palindrome
*/

import java.util.*;

public class PalindromeLinkedList {
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
    static void printList(Node head)
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

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t>0)
        {
            int n = sc.nextInt();
            //int k = sc.nextInt();
            PalindromeLinkedList llist = new PalindromeLinkedList();
            //int n=Integer.parseInt(br.readLine());
            int a1=sc.nextInt();
            Node head= new Node(a1);
            Node tail = head;
            for (int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }

            if(solve(head) == true)
                System.out.println(1);
            else
                System.out.println(0);
            t--;
        }
    }

    //Function to check whether the list is palindrome.
    public static boolean solve(Node head) {
        //Your code here
        if(head==null || head.next==null) return true;

        Node slow = head;
        Node fast = head;
        Node beforMid = head;
        while (fast!=null && fast.next!=null){
            beforMid = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        beforMid.next = null;

        Node secondHalf = null;
        if(fast!=null) secondHalf = slow.next;
        else secondHalf = slow;

        secondHalf = reverse(secondHalf);

        for(Node p=head, q=secondHalf; p!=null && q!=null; p=p.next, q=q.next)
            if(p.data != q.data) return false;

        return true;
    }

    public static Node reverse(Node head){
        Node prev = null;
        Node curr = head;
        Node next;
        while (curr != null){
            next = curr.next;
            curr.next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
}
