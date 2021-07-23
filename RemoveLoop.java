/*
https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
Tags: Linked List
*/

import java.util.Scanner;


public class RemoveLoop {
    static class Node {
        int data;
        Node next;
    }

    public static Node newNode(int data){
        Node temp = new Node();
        temp.data = data;
        temp.next = null;
        return temp;
    }

    public static void makeLoop(Node head, int x){
        if (x == 0)
            return;
        Node curr = head;
        Node last = head;

        int currentPosition = 1;
        while (currentPosition < x)
        {
            curr = curr.next;
            currentPosition++;
        }

        while (last.next != null)
            last = last.next;
        last.next = curr;
    }

    public static boolean detectLoop(Node head){
        Node hare = head.next;
        Node tortoise = head;
        while( hare != tortoise )
        {
            if(hare==null || hare.next==null) return false;
            hare = hare.next.next;
            tortoise = tortoise.next;
        }
        return true;
    }

    public static int length(Node head){
        int ret=0;
        while(head!=null)
        {
            ret += 1;
            head = head.next;
        }
        return ret;
    }

    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t--> 0)
        {
            int n = sc.nextInt();

            int num = sc.nextInt();
            Node head = newNode(num);
            Node tail = head;

            for(int i=0; i<n-1; i++)
            {
                num = sc.nextInt();
                tail.next = newNode(num);
                tail = tail.next;
            }

            int pos = sc.nextInt();
            makeLoop(head, pos);

            solve(head);

            if( detectLoop(head) || length(head)!=n )
                System.out.println("0");
            else
                System.out.println("1");
        }
    }

    //Function to remove a loop in the linked list.
    private static void solve(Node head){
        // code here
        Node p,q;
        for(p=head, q=head.next; q!=null && q.next!=null; p=p.next, q=q.next.next)
            if(p==q) removeLoop(head,p);
    }

    private static void removeLoop(Node head, Node loopNode){
        Node p = loopNode;
        Node q = loopNode;

        int k = 1;
        while (p.next != q){
            p = p.next;
            k++;
        }

        p = head;
        q = head;
        for(int i=0; i<k; i++)
            q = q.next;

        while (p != q){
            p = p.next;
            q = q.next;
        }

        while (q.next != p)
            q = q.next;

        q.next = null;
    }

}
