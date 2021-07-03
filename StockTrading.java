/*
    https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
    Tags:  Arrays, Greedy, Dynamic Programming
*/

import java.io.*;
import java.util.*;

public class StockTrading {
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
        while(t-->0){
            int n = Integer.parseInt(br.readLine().trim());
            int A[] = new int[n];
            String inputLine[] = br.readLine().trim().split(" ");
            for(int i=0; i<n; i++){
                A[i] = Integer.parseInt(inputLine[i]);
            }
            int p = 0;
            for(int i=0; i<n-1; i++)
                p += Math.max(0,A[i+1]-A[i]);

            ArrayList<ArrayList<Integer> > ans = solve(A, n);
            if(ans.size()==0)
                System.out.print("No Profit");
            else{
                int c=0;
                for(int i=0; i<ans.size(); i++)
                    c += A[ans.get(i).get(1)]-A[ans.get(i).get(0)];

                if(c==p)
                    System.out.print(1);
                else
                    System.out.print(0);
            }System.out.println();
        }
    }

    private static ArrayList<ArrayList<Integer>> solve(int []prices, int n) {
        // code here
        ArrayList<ArrayList<Integer>> table = new ArrayList<>();

        for(int i=0; i<n-1; i++){
            if(prices[i]<prices[i+1]){
                ArrayList<Integer> pair = new ArrayList<>();
                pair.add(i);
                pair.add(i+1);
                table.add(pair);
            }
        }
        return table;
    }
}
