/*
https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
Tags: Linked List
*/

import java.util.*;
import java.io.*;

public class PairSwapLinkedList {

    static class Node{
        int data;
        Node next;

        Node(int x){
            data = x;
            next = null;
        }

    }

    static void printList(Node node)
    {
        while (node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t > 0){
            int n = sc.nextInt();

            Node head = new Node(sc.nextInt());
            Node tail = head;
            HashMap<Node, Integer> mp = new HashMap<Node, Integer>();
            mp.put(head, head.data);
            for(int i=0; i<n-1; i++)
            {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
                mp.put(tail, tail.data);
            }

            Node failure = new Node(-1);

            head = solve(head);

            Node temp = head;
            int f = 0;
            while (temp != null)
            {
                if(mp.get(temp) != temp.data){
                    f = 1;
                }
                temp = temp.next;
            }

            if(f==1){
                printList(failure);
            }
            else{
                printList(head);
            }
            t--;
        }
    }

    // Function to pairwise swap elements of a linked list.
    // It should returns head of the modified list
    private static Node solve(Node head) {
        // code here
        if(head==null || head.next==null) return head;

        Node prev = head;
        Node curr = head.next;
        head = curr;

        while (true){
            Node temp = curr.next;
            curr.next = prev;

            if(temp==null || temp.next==null){
                prev.next = temp;
                break;
            }

            prev.next = temp.next;

            //updation;
            prev = temp;
            curr = prev.next;
        }

        return head;
    }
}