/*
https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
Tags: Hash, Sliding-window
*/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class DistinctInWindow {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();

            ArrayList<Integer> ans = solve(a, n, k);

            for (Integer val: ans)
                System.out.print(val+" ");
            System.out.println();
            t--;
        }
    }

    private static ArrayList<Integer> solve(int[] array, int n, int k) {
        // code here
        Map<Integer,Integer> map = new HashMap<>();
        ArrayList<Integer> result = new ArrayList<>();

        for(int i=0,j=0; i<=n-k; i++){
            if(i==0){
                while (j<k){
                    map.merge(array[j],1,Integer::sum);
                    j++;
                }
                result.add(map.size());
            }
            else{
                map.merge(array[j],1,Integer::sum);

                Integer count = map.get(array[i-1]);
                if(count == 1) map.remove(array[i-1]);
                else map.put(array[i-1],count-1);

                result.add(map.size());
                j++;
            }
        }
        return result;
    }

}

