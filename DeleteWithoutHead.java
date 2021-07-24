/*
https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
Tags: Linked List
*/

import java.util.*;

public class DeleteWithoutHead {
    static class Node
    {
        int data ;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }

    Node head;
    Node tail;

    void printList(Node head)
    {
        Node tnode = head;
        while(tnode != null)
        {
            System.out.print(tnode.data+ " ");
            tnode = tnode.next;
        }
        System.out.println();
    }

    void addToTheLast(Node node)
    {

        if(head == null)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail.next = node;
            tail = node;
        }
    }

    Node search_Node(Node head, int k)
    {
        Node current = head;
        while(current != null)
        {
            if(current.data == k)
                break;
            current = current.next;
        }
        return current;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            DeleteWithoutHead llist = new DeleteWithoutHead();
            //int n=Integer.parseInt(br.readLine());
            int a1=sc.nextInt();
            Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }

            int k = sc.nextInt();
            Node del = llist.search_Node(llist.head,k);

            if(del != null && del.next != null) {
                solve(del);
            }
            llist.printList(llist.head);
            t--;
        }
    }

    private static void solve(Node del) {
        // Your code here
        if(del.next == null)
            del = null;
        else {
            Node temp = del.next;
            del.data = temp.data;
            del.next = temp.next;
            temp.next = null;
        }
    }
}