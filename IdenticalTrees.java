/*
https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
Tags: Tree
*/

import java.io.*;
import java.util.*;

public class IdenticalTrees {

    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data = data;
            left=null;
            right=null;
        }
    }

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    static void printInorder(Node root) {
        if (root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String s1 = br.readLine();
            String s2 = br.readLine();
            Node root1 = buildTree(s1);
            Node root2 = buildTree(s2);
            //System.out.println(g.isIdentical(root,roott));
            boolean b = solve(root1, root2);
            if (b == true)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }

    private static boolean solve(Node root1, Node root2){
        return isIdentical(root1,root2);
    }
    //Function to check if two trees are identical.
    private static boolean isIdentical(Node p, Node q) {
        // Code Here
        if(p==null && q==null)
            return true;
        if(p!=null && q!=null)
            return p.data==q.data && isIdentical(p.left,q.left) && isIdentical(p.right,q.right);
        else
            return false;
    }
}