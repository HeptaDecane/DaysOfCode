/*
https://practice.geeksforgeeks.org/problems/combination-sum-part-21208/1
Tags: Backtracking, Recursion
*/

import java.io.*;
import java.util.*;
import java.lang.*;

public class CombinationsSum2 {
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int A[]= new int[N];
            for(int i = 0; i < N; i++)
                A[i] = Integer.parseInt(input_line[i]);
            int B = Integer.parseInt(read.readLine());

            List<List<Integer>> result = new ArrayList<>();
            result = solve(A, N, B);
            if(result.size() == 0)
                System.out.println("Empty");
            else{
                for(int i = 0;i < result.size(); i++){
                    System.out.print("(");
                    for(int j = 0;j < result.get(i).size();j++){
                        System.out.print(result.get(i).get(j));
                        if(j != result.get(i).size() - 1)
                            System.out.print(" ");
                    }
                    System.out.print(")");
                }
                System.out.println();
            }
        }
    }

    private static List<List<Integer>> result = null;
    private static List<List<Integer>> solve(int[] array, int n, int target) {
        // code here
        result = new ArrayList<>();
        Arrays.sort(array);
        recursion(0,array,target,new ArrayList<>());
        return result;
    }

    private static void recursion(int index, int[] array, int target, List<Integer> list){
        if(target == 0) {
            result.add(new ArrayList<>(list));
            return;
        }
        for (int i=index; i<array.length; i++){
            if(i>index && array[i]==array[i-1]) continue;
            if(array[i] > target) break;

            list.add(array[i]);
            recursion(i+1,array,target-array[i],list);
            list.remove(list.size()-1);
        }
    }
}