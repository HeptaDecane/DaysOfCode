/*
    https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
    Tags: Arrays, Matrix
*/

import java.io.*;
import java.util.*;

public class MatrixSpiral
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0)
        {
            int r = sc.nextInt();
            int c = sc.nextInt();

            int matrix[][] = new int[r][c];

            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                    matrix[i][j] = sc.nextInt();
            }

            ArrayList<Integer> ans = solve(matrix, r, c);
            for (Integer val: ans)
                System.out.print(val+" ");
            System.out.println();
        }
    }

    //Function to return a list of integers denoting spiral traversal of matrix.
    private static ArrayList<Integer> solve(int[][] matrix, int r, int c) {
        // code here
        ArrayList<Integer> spiral = new ArrayList<>();
        int depth = 0;
        int maxDepth = (Math.min(r,c)-1)/2;
        int n = r*c;

        while (depth <= maxDepth){
            int rowEnd = r-depth-1;
            int colEnd = c-depth-1;

            for(int i=depth; i<colEnd && spiral.size()<n; i++)
                spiral.add(matrix[depth][i]);

            for(int i=depth; i<rowEnd && spiral.size()<n; i++)
                spiral.add(matrix[i][colEnd]);

            for(int i=colEnd; i>depth && spiral.size()<n; i--)
                spiral.add(matrix[rowEnd][i]);

            for(int i=rowEnd; i>depth && spiral.size()<n; i--)
                spiral.add(matrix[i][depth]);

            depth++;
        }

        if(spiral.size()<n)
            spiral.add(matrix[maxDepth][maxDepth]);

        return spiral;
    }
}

/*
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
    
    
    00 01 02 03 04 14 24 34 33 32 31 30 20 10
*/