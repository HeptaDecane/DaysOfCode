/*
https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
Tags: Tree
*/

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

public class SerializeBinaryTree {

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

    static Node buildTree(String str){

        if(str.length()==0 || str.charAt(0)=='N'){
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
        while(queue.size()>0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if(!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if(i >= ip.length)
                break;

            currVal = ip[i];

            // If the right child is not null
            if(!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }
    static void deletetree( Node root)
    {
        if(root == null)
            return;
        deletetree(root.left);
        deletetree(root.right);
        root.left=null;
        root.right=null;
    }
    static void printInorder(Node root){
        if(root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data+" ");

        printInorder(root.right);
    }

    public static void main (String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

        int t=Integer.parseInt(br.readLine());
        while(t-- > 0){
            String s= br.readLine();
            Node root = buildTree(s);

            Tree tr=new Tree();
            ArrayList<Integer> A=new ArrayList<Integer>();
            tr.serialize(root, A);
            deletetree(root);
            root = null;

            Node getRoot=tr.deSerialize(A);
            printInorder(getRoot);
            System.out.println();
        }
    }

    static class Tree
    {
        //Function to serialize a tree and return a list containing nodes of tree.
        public void serialize(Node root, ArrayList<Integer> array) {
            //code here
            if(root == null)
                array.add(null);
            else{
                array.add(root.data);
                serialize(root.left, array);
                serialize(root.right, array);
            }
        }

        //Function to deserialize a list and construct the tree.
        private int index = 0;
        public Node deSerialize(ArrayList<Integer> array) {
            //code here
            if(index == array.size()) return null;

            if (array.get(index) == null){
                index++;
                return null;
            }
            Node root = new Node(array.get(index));
            index++;
            root.left = deSerialize(array);
            root.right = deSerialize(array);

            return root;
        }
    }
}
