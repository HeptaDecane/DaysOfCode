/*
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
Tags: Linked List
*/

import java.util.*;

public class LinkedListAddition {

    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }


    static void printList(Node n){
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {

            int n = sc.nextInt();
            int val = sc.nextInt();

            Node first = new Node(val);
            Node tail = first;
            for(int i=0; i<n-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }

            int m = sc.nextInt();
            val = sc.nextInt();

            Node second = new Node(val);
            tail = second;
            for(int i=0; i<m-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }

            Node res = solve(first, second);
            printList(res);
        }
    }

    //Function to add two numbers represented by linked list.
    private static Node solve(Node first, Node second){
        // code here
        // return head of sum list
        first = reverse(first);
        second = reverse(second);

        Node head = null;
        int carry = 0;
        while (first!=null || second!=null){
            Node temp = null;
            if(first == null){
                temp = new Node((second.data+carry)%10);
                carry = (second.data+carry)/10;
                second = second.next;
            }
            else if(second == null){
                temp = new Node((first.data+carry)%10);
                carry = (first.data+carry)/10;
                first = first.next;
            }
            else {
                temp = new Node((first.data+second.data+carry)%10);
                carry = (first.data+second.data+carry)/10;
                first = first.next;
                second = second.next;
            }
            temp.next = head;
            head = temp;
        }

        if(carry != 0){
            Node temp = new Node(carry);
            temp.next = head;
            head = temp;
        }

        return head;
    }

    private static Node reverse(Node head){
        Node previous = null;
        Node current = head;
        Node next;

        while (current != null){
            next = current.next;
            current.next = previous;

            previous = current;
            current = next;
        }
        return previous;
    }
}
