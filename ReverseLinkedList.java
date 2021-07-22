/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
Tags: Linked List
*/

import java.io.IOException;
import java.util.Scanner;

/* linked list node class:

class Node {
    int value;
    Node next;
    Node(int value) {
        this.value = value;
    }
}

*/

public class ReverseLinkedList {

    static class Node{
        int data;
        Node next;

        Node(int x){
            data = x;
            next = null;
        }

    }

    public static void main(String args[]) throws IOException {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t > 0){

            int n = sc.nextInt();

            Node head = new Node(sc.nextInt());
            Node tail = head;

            for(int i=0; i<n-1; i++) {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }

            head = solve(head);
            printList(head);
            t--;
        }
    }

    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    //Function to reverse a linked list.
    private static Node solve(Node head) {
        // code here
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


// 0-->1-->2-->3-->4-->5-->6-->7-->8-->9