/*
Tags: Tree, Stack
*/
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

public class TreeTraversal {

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

    public static void main(String[] args) {
        /*
                Construct the following tree
                       1
                     /   \
                    /     \
                   2       3
                  /      /   \
                 /      /     \
                4      5       6
                      / \
                     /   \
                    7     8
        */

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);
        root.right.left.left = new Node(7);
        root.right.left.right = new Node(8);

        System.out.println("inorder   : "+inorder(root));
        System.out.println("preorder  : "+preorder(root));
        System.out.println("postorder : "+postorder(root));
    }

    // root.left root.data root.right
    private static ArrayList<Integer> inorder(Node root){
        ArrayList<Integer> result = new ArrayList<>();
        Stack<Node> stack = new Stack<>();
        Node node = root;

        while (!stack.isEmpty() || node!=null){
            if(node != null){
                stack.push(node);
                node = node.left;
            } else {
                node = stack.pop();
                result.add(node.data);
                node = node.right;
            }
        }

        return result;
    }

    // root.data root.left root.right
    private static ArrayList<Integer> preorder(Node root){
        ArrayList<Integer> result = new ArrayList<>();
        Stack<Node> stack = new Stack<>();
        Node node = root;

        while (!stack.isEmpty() || node!=null){
            if(node != null){
                result.add(node.data);

                if(node.right != null)
                    stack.push(node.right);

                node = node.left;
            }
            else node = stack.pop();
        }
        return result;
    }

    // root.left root.right root.data
    private static ArrayList<Integer> postorder(Node root){
        ArrayList<Integer> result = new ArrayList<>();
        Stack<Node> stack = new Stack<>();
        Node node = root;

        while (!stack.isEmpty() || node!=null){
            if(node != null){
                result.add(node.data);

                if(node.left != null)
                    stack.push(node.left);

                node = node.right;
            }
            else node = stack.pop();
        }

        Collections.reverse(result);
        return result;
    }
}
