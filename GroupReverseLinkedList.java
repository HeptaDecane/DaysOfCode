/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
Tags: Linked List
*/

import java.util.*;
import java.lang.*;

public class GroupReverseLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int key)
        {
            data = key;
            next = null;
        }
    }

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0)
        {
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;
            for(int i = 1; i < n; i++)
            {
                int a = sc.nextInt();
                // addToTheLast(new Node(a));
                tail.next = new Node(a);
                tail =tail.next;
            }

            int k = sc.nextInt();
            Node res = solve(head, k);
            printList(res);
            System.out.println();
        }
    }

    public static void printList(Node node) {
        while(node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }

    public static Node solve(Node head, int k) {
        //Your code here
        Stack<Node> stack = new Stack<>();
        Node current = head;
        Node last = null;

        while (current!=null){
            for(int i=0; current!=null && i<k; i++){
                stack.push(current);
                current = current.next;
            }

            while (!stack.isEmpty()){
                if(last == null){
                    last = stack.pop();
                    head = last;
                }
                else {
                    last.next = stack.pop();
                    last = last.next;
                }
            }
        }
        last.next = null;

        return head;
    }

}
