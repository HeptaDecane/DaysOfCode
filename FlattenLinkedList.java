/*
https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
Tags: Linked List
*/

import java.util.Scanner;

/*Node class  used in the program
class Node
{
	int data;
	Node next;
	Node bottom;

	Node(int d)
	{
		data = d;
		next = null;
		bottom = null;
	}
}
*/

public class FlattenLinkedList {
    static class Node {
        int data;
        Node next;
        Node bottom;

        Node(int d)
        {
            data = d;
            next = null;
            bottom = null;
        }
    }


    Node head;

    void printList(Node node)
    {
        //Node temp = head;
        while (node != null)
        {
            System.out.print(node.data + " ");
            node =node.bottom;
        }
        System.out.println();
    }
    public  static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        FlattenLinkedList list = new FlattenLinkedList();
        while(t>0)
        {
            int N = sc.nextInt();
            int arr[] = new int[N];
            for(int i=0;i<N;i++)
                arr[i] = sc.nextInt();

            Node temp = null;
            Node tempB = null;
            Node pre = null;
            Node preB = null;
            int flag=1;
            int flag1=1;
            for(int i=0; i<N;i++)
            {
                int m = arr[i];
                m--;
                int a1 = sc.nextInt();
                temp = new Node(a1);
                if(flag == 1)
                {
                    list.head = temp;
                    pre = temp;
                    flag = 0;
                    flag1 = 1;
                }
                else
                {
                    pre.next = temp;
                    pre = temp;
                    flag1 = 1;
                }

                for(int j=0;j<m;j++)
                {
                    int a = sc.nextInt();
                    tempB = new Node(a);
                    if(flag1 == 1)
                    {
                        temp.bottom = tempB;
                        preB = tempB;
                        flag1 = 0;
                    }
                    else
                    {
                        preB.bottom = tempB;
                        preB = tempB;
                    }
                }

            }
            //list.printList();
            Node root = solve(list.head);
            list.printList(root);

            t--;
        }
    }

    private static Node solve(Node root) {
        // Your code here
        Node result = null;
        for(Node p=root; p!=null; p=p.next)
            result = merge(result,p);
        return result;
    }

    private static Node merge(Node head1, Node head2){
        Node p = head1;
        Node q = head2;
        Node head = new Node(-1);
        Node tail = head;

        while (true){

            if(p == null){
                tail.bottom = q;
                break;
            }
            else if(q == null){
                tail.bottom = p;
                break;
            }


            if(p.data < q.data){
                tail.bottom = p;
                p = p.bottom;
            }
            else {
                tail.bottom = q;
                q = q.bottom;
            }

            tail = tail.bottom;
        }
        return head.bottom;
    }

}
