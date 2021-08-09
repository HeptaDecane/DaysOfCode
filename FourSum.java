/*
https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
Tags:
*/

import java.io.*;
import java.util.*;

public class FourSum {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {
            String[] nk = br.readLine().trim().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            ArrayList<ArrayList<Integer>> ans = solve(a, k);
            for (ArrayList<Integer> v : ans) {
                for (int u : v) {
                    System.out.print(u + " ");
                }
                System.out.print("$");
            }
            if (ans.isEmpty()) {
                System.out.print(-1);
            }
            System.out.println();
        }
    }


    private static ArrayList<ArrayList<Integer>> solve(int[] arr, int k) {
        // code here
        int n = arr.length;
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        Arrays.sort(arr);

        for(int i=0; i<n; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;

            for(int j=i+1; j<n; j++){
                if(j>i+1 && arr[j] == arr[j-1]) continue;

                int target = k-arr[i]-arr[j];
                int left = j+1;
                int right = n-1;

                while (left < right){
                    int sum = arr[left] + arr[right];
                    if(sum < target) left++;
                    else if (sum > target) right--;
                    else {
                        ArrayList<Integer> quad = new ArrayList<>();
                        quad.add(arr[i]);
                        quad.add(arr[j]);
                        quad.add(arr[left]);
                        quad.add(arr[right]);
                        result.add(quad);
                        left++;
                        right--;
                        while (left<right && arr[left]==quad.get(2)) left++;
                        while (left<right && arr[right]==quad.get(3)) right--;
                    }
                }
            }
        }
        return result;
    }

}