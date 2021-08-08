/*
https://practice.geeksforgeeks.org/problems/josephus-problem/1
Tags: Bit Magic, Recursion
*/

import java.util.ArrayList;
import java.util.Scanner;
public class JosephusProblem {
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);

        int T=sc.nextInt();//testcases
        while(T-->0)
        {
            int n,k;
            //taking input n and k
            n=sc.nextInt();
            k=sc.nextInt();

            //calling josephus() function
            System.out.println(solve(n,k));
        }
    }

    public static int solve(int n, int k) {
        //Your code here
        ArrayList<Integer> list = new ArrayList<>();

        for(int i=0; i<n; i++)
            list.add(i);

        int i = (k-1)%list.size();
        while (true){
            if(list.size() == 1) break;
            else list.remove(i);
            i = (i+k-1)%list.size();
        }
        return list.remove(0)+1;
    }
}

