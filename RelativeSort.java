/*
https://practice.geeksforgeeks.org/problems/relative-sorting4323/1
Tags: Hash, Searching, Sorting
*/

import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


public class RelativeSort {
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);

        int t=sc.nextInt();

        while(t-->0)
        {
            int n=sc.nextInt();
            int m=sc.nextInt();
            int a1[]=new int[n];
            int a2[]=new int[m];

            for(int i=0;i<n;i++)
                a1[i]=sc.nextInt();

            for(int i=0;i<m;i++)
                a2[i]=sc.nextInt();
            a1 = solve(a1,n,a2,m);
            for(int x:a1)
                System.out.print(x+" ");

            System.out.println();
        }
    }

    //Function to sort an array according to the other array.
    private static int[] solve(int[] array, int n, int[] reference, int m) {
        //Your code here
        Map<Integer, Integer> map = new TreeMap<>();

        for(int element : array){
            Integer count = map.get(element);
            if(count == null)
                map.put(element, 1);
            else
                map.put(element, count+1);
        }

        int[] sorted = new int[n];
        int index = 0;

        for(int element : reference){
            Integer count = map.get(element);
            if(count == null) continue;

            for(int i=0; i<count; i++)
                sorted[index++] = element;

            map.remove(element);
        }

        for(int key : map.keySet()){
            Integer count = map.get(key);
            for(int i=0; i<count; i++)
                sorted[index++] = key;
        }

        return sorted;
    }

}
