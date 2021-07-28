/*
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
Tags: Arrays, Queue, Sliding-window
*/

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class MaxOfSubarray {
    public static void main(String args[])
    {
        //taking input using class Scanner
        Scanner sc = new Scanner(System.in);

        //taking total count of testcases
        int t = sc.nextInt();



        while(t-- > 0)
        {
            //taking total number of elements
            int n = sc.nextInt();

            //taking size of subArrays 
            int k = sc.nextInt();

            //Declaring and Intializing an array of size n
            int arr[] = new int[n];

            //adding all the elements to the array 
            for(int i = 0; i <n; i++)
            {
                arr[i] =sc.nextInt();
            }

            //Calling the method max_of_subarrays of class solve
            //and storing the result in an ArrayList
            ArrayList <Integer> res = solve(arr, n, k);

            //printing the elements of the ArrayList
            for (int i = 0; i < res.size(); i++)
                System.out.print (res.get (i) + " ");
            System.out.println();
        }
    }

    //Function to find maximum of each subarray of size k.
    private static ArrayList<Integer> solve(int[] arr, int n, int k) {
        // Your code here
        Deque<Integer> deque = new LinkedList<>();
        ArrayList<Integer> result = new ArrayList<>();

        for(int i=0; i<k; i++){
            while (!deque.isEmpty() && arr[i]>=arr[deque.peekLast()])
                deque.removeLast();

            deque.addLast(i);
        }

        for(int i=k; i<n; i++){
            result.add(arr[deque.peekFirst()]);

            while (!deque.isEmpty() && deque.peekFirst()<=i-k)
                deque.removeFirst();

            while (!deque.isEmpty() && arr[i]>=arr[deque.peekLast()])
                deque.removeLast();

            deque.addLast(i);
        }

        result.add(arr[deque.peekFirst()]);
        return result;
    }
}
