/*
https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/1
Tags: Hash, Arrays, Sorting
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class FrequencySort {

    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(sc.readLine());
        while(n != 0)
        {
            int size = Integer.parseInt(sc.readLine());
            int arr[] = new int[size];
            String[] temp = sc.readLine().trim().split("\\s+");

            for(int i = 0; i < size; i++)
                arr[i] = Integer.parseInt(temp[i]);

            ArrayList<Integer> ans = new ArrayList<Integer>();
            ans = solve(arr, size);
            for(int i=0;i<ans.size();i++)
                System.out.print(ans.get(i)+" ");
            System.out.println();
            n--;
        }
    }

    //Function to sort the array according to frequency of elements.
    private static ArrayList<Integer> solve(int[] arr, int n) {
        // add your code here
        Map<Integer,Integer> map = new HashMap<>();

        for(int element : arr){
            Integer count = map.get(element);
            if(count == null)
                map.put(element,1);
            else
                map.put(element,count+1);
        }

        PriorityQueue<Pair> sorted = new PriorityQueue<>((first, second) -> {
            if(first.count == second.count)
                return first.entry - second.entry;
            else
                return second.count - first.count;
        });

        for(int key : map.keySet())
            sorted.add(new Pair(key,map.get(key)));

        ArrayList<Integer> result = new ArrayList<>();
        while (!sorted.isEmpty()){
            Pair pair = sorted.poll();
            for(int i=0; i<pair.count; i++)
                result.add(pair.entry);
        }

        return result;
    }

    static class Pair{
        public int entry;
        public int count;

        public Pair(){
            this(0,0);
        }

        public Pair(int entry, int count) {
            this.entry = entry;
            this.count = count;
        }

    }
}