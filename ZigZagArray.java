/*
    https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1
    Tags: Arrays
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ZigZagArray {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            zigZag(arr, n);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }

    private static void zigZag(int[] arr, int n) {
        // code here
        for(int i=1; i<n; i+=2){
            if(arr[i-1] > arr[i])
                swap(arr,i-1,i);
            if(i<n-1) {
                if (arr[i] < arr[i + 1])
                    swap(arr, i, i + 1);
            }
        }
    }

    private static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}