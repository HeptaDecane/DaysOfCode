/*
https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
Tags: Graph, Matrix, Recursion, DFS, Algorithms
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class FloodFill {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] image =  new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S2 = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++)
                    image[i][j] = Integer.parseInt(S2[j]);
            }
            String[] S3 = br.readLine().trim().split(" ");
            int sr = Integer.parseInt(S3[0]);
            int sc = Integer.parseInt(S3[1]);
            int newColor = Integer.parseInt(S3[2]);
            int[][] ans = solve(image, sr, sc, newColor);
            for(int i = 0; i < ans.length; i++){
                for(int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }
        }
    }

    static class Coordinate{
        public int x,y;
        public Coordinate(int x, int y){
            this.x = x;
            this.y = y;
        }
        public Coordinate(){
            this(0,0);
        }
    }

    private static boolean isValid(int[][] image, int x, int y,int previousColor, int newColor){
        int n = image.length;
        int m = image[0].length;

        return x>=0 && x<n && y>=0 && y<m && image[x][y]==previousColor && image[x][y]!=newColor;
    }

    private static int[][] solve(int[][] image, int sr, int sc, int newColor) {
        // Code here
        Queue<Coordinate> queue = new LinkedList<>();
        queue.add(new Coordinate(sr,sc));

        int previousColor = image[sr][sc];
        image[sr][sc] = newColor;
        while (!queue.isEmpty()){
            Coordinate pixel = queue.poll();
            int x = pixel.x;
            int y = pixel.y;

            if(isValid(image,x+1,y,previousColor,newColor)) {
                image[x+1][y] = newColor;
                queue.add(new Coordinate(x + 1, y));
            }

            if(isValid(image,x-1,y,previousColor,newColor)) {
                image[x-1][y] = newColor;
                queue.add(new Coordinate(x - 1, y));
            }

            if(isValid(image,x,y+1,previousColor,newColor)) {
                image[x][y+1] = newColor;
                queue.add(new Coordinate(x, y + 1));
            }

            if(isValid(image,x,y-1,previousColor,newColor)) {
                image[x][y-1] = newColor;
                queue.add(new Coordinate(x, y - 1));
            }
        }
        return image;
    }
}
