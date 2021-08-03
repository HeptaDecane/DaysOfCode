/*
https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
Tags: Tree
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;


public class CheckBalancedTree {

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
    static void printInorder(Node root)
    {
        if(root == null)
            return;

        printInorder(root.left);
        System.out.print(root.data+" ");

        printInorder(root.right);
    }

    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t=Integer.parseInt(br.readLine());

        while(t > 0){
            String s = br.readLine();
            Node root = buildTree(s);

            if(solve(root))
                System.out.println(1);
            else
                System.out.println(0);
            t--;

        }
    }

    static class Int{
        public int value = 0;
        public Int(){
            this(0);
        }
        public Int(int value){
            this.value = value;
        }
    }

    //Function to check whether a binary tree is balanced or not.
    private static boolean solve(Node root){
        // your code here
        Int height = new Int();
        return recursion(root,height);
    }

    private static boolean recursion(Node node, Int height){
        if(node == null){
            height.value = 0;
            return true;
        }

        Int leftHeight = new Int();
        Int rightHeight = new Int();

        boolean leftBalanced = recursion(node.left,leftHeight);
        boolean rightBalanced = recursion(node.right,rightHeight);

        height.value = Math.max(leftHeight.value, rightHeight.value) + 1;
        return Math.abs(leftHeight.value - rightHeight.value)<=1 && leftBalanced && rightBalanced;
    }

}


