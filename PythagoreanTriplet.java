/*
    https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
    Tags:  Arrays, Two Pointer Algorithm
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class PythagoreanTriplet {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] inputLine = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            boolean ans = solve(arr, n);
            System.out.println(ans ? "Yes" : "No");
        }
    }

    private static boolean solve(int[] arr, int n) {
        // code here
        Arrays.sort(arr);

        for(int a : arr){
            int left = 0;
            int right = n-1;

            while (left < right){
                int x = arr[left]*arr[left];
                int y = arr[right]*arr[right];
                int z = a*a;

                if (x+y < z) left++;
                else if(x+y > z) right--;
                else return true;
            }
        }
        return false;
    }
}

