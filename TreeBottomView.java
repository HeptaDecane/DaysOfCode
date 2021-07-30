/*
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
Tags: Tree, Level order traversal
*/

import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;


public class TreeBottomView {

    static class Node
    {
        int data; //data of the node
        int hd; //horizontal distance of the node
        Node left, right; //left and right references

        // Constructor of tree node
        public Node(int key)
        {
            data = key;
            hd = Integer.MAX_VALUE;
            left = right = null;
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
            String s = br.readLine();
            Node root = buildTree(s);
            ArrayList<Integer> res = solve(root);
            for (Integer num : res) System.out.print(num + " ");
            System.out.println();
        }
    }

    static class Pair{
        public Node node;
        public int hDistance;

        public Pair(Node node, int hDistance){
            this.node = node;
            this.hDistance = hDistance;
        }
    }

    //Function to return a list containing the bottom view of the given tree.
    public static ArrayList<Integer> solve(Node root) {
        // Code here
        Queue<Pair> queue = new LinkedList<>();
        Map<Integer,Integer> map = new TreeMap<>();

        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()){
            Node node = queue.peek().node;
            int hDistance = queue.peek().hDistance;
            queue.remove();
            map.put(hDistance,node.data);

            if(node.left != null)
                queue.add(new Pair(node.left,hDistance-1));
            if(node.right != null)
                queue.add(new Pair(node.right,hDistance+1));
        }
        ArrayList<Integer> result = new ArrayList<>(map.values());
        return result;
    }
}