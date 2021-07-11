/*
    https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
    Tags: Arrays, Sorting
*/

import java.util.*;
import java.io.*;

public class LargestArrayNumber {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            String[] arr = br.readLine().trim().split(" ");

            String ans = solve(arr);
            System.out.println(ans);
        }
    }

    private static String solve(String[] arr) {
        // code here
        Arrays.sort(arr, (o1, o2) -> {
            return (o2+o1).compareTo(o1+o2);
        });

        StringBuilder result = new StringBuilder();
        for(String element : arr)
            result.append(element);

        return result.toString();
    }

}