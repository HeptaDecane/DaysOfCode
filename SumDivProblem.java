/*
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
Tags: Arrays, Hash
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class SumDivProblem {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String s1 = br.readLine().trim();
            String[] S1 = s1.split(" ");
            int n = Integer.parseInt(S1[0]);
            int k = Integer.parseInt(S1[1]);
            String s2 = br.readLine().trim();
            String[] S2 = s2.split(" ");
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(S2[i]);
            }
            boolean ans = solve(nums, k);
            if (ans)
                System.out.println("True");
            else
                System.out.println("False");
        }
    }

    private static boolean solve(int[] nums, int k) {
        // Code here
        Map<Integer,Integer> map = new HashMap<>();

        for(int number : nums)
            map.merge(number%k,1,Integer::sum);

        for(int key : map.keySet()){
            Integer a = map.get(key);
            Integer b = map.get(k-key);

            if(key==0 && a%2==0) continue;
            if(!a.equals(b)) return false;
        }

        return true;
    }
}