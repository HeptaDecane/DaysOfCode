/*
https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1
Tags: Arrays, Hash
*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class PairedSum {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            StringTokenizer stt = new StringTokenizer(br.readLine());

            long N = Long.parseLong(stt.nextToken());
            long M = Long.parseLong(stt.nextToken());
            long X = Long.parseLong(stt.nextToken());
            long A[] = new long[(int)(N)];
            long B[] = new long[(int)(M)];


            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < N; i++) {
                A[i] = Long.parseLong(inputLine[i]);
            }
            String inputLine1[] = br.readLine().trim().split(" ");
            for (int i = 0; i < M; i++) {
                B[i] = Long.parseLong(inputLine1[i]);
            }

            Pair [] answer = solve(A, B, N, M, X);
            int sz = answer.length;

            if(sz==0)
                System.out.println(-1);
            else{
                StringBuilder output = new StringBuilder();
                for(int i=0;i<sz;i++){
                    if(i<sz-1)
                        output.append(answer[i].first +" "+ answer[i].second + ", ");
                    else
                        output.append(answer[i].first +" "+ answer[i].second);

                }
                System.out.println(output);
            }
        }

    }

    static class Pair {
        long first, second;
        public Pair(long first, long second)
        {
            this.first = first;
            this.second = second;
        }
    }

    private static Pair[] solve(long[] array1, long[] array2, long n, long m, long target) {
        // Your code goes here
        Set<Long> set = new HashSet<>();

        for (long element : array2)
            set.add(element);

        Arrays.sort(array1);

        ArrayList<Pair> result = new ArrayList<>();
        for(long element : array1){
            long diff = target - element;
            if(set.contains(diff))
                result.add(new Pair(element,diff));
        }

        return result.toArray(new Pair[0]);
    }
}
