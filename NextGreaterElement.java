/*
https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
Tags: Stack
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class NextGreaterElement {

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            String inputLine[] = br.readLine().trim().split(" ");
            long[] arr = new long[n];
            for(int i=0; i<n; i++)arr[i]=Long.parseLong(inputLine[i]);
            long[] res = solve(arr, n);
            for (int i = 0; i < n; i++)
                System.out.print(res[i] + " ");
            System.out.println();
        }
    }

    //Function to find the next greater element for each element of the array.
    private static long[] solve(long[] arr, int n) {
        // Your code here
        Stack<Integer> stack = new Stack<>();
        long[] result = new long[n];

        for(int i=0; i<n; i++){
            if(stack.isEmpty())
                stack.push(i);
            else {
                while (!stack.isEmpty() && arr[i]>arr[stack.peek()]){
                    result[stack.peek()] = arr[i];
                    stack.pop();
                }
                stack.push(i);
            }
        }

        while (!stack.isEmpty()){
            result[stack.peek()] = -1;
            stack.pop();
        }

        return result;
    }
}


