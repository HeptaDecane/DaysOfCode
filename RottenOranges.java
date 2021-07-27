/*
https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
Tags: BFS, Matrix, Queue
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class RottenOranges {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int[][] grid = new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            int ans = solve(grid);
            System.out.println(ans);
        }
    }

    // Code here

    static class Cell{
        private final int x,y;
        public static final Cell delimiter = new Cell(-1,-1);

        public Cell(){
            this(0,0);
        }

        public Cell(int x, int y){
            this.x = x;
            this.y = y;
        }

        public boolean isDelimiter(){
            return x==-1 && y==-1;
        }

    }

    //Function to find minimum time required to rot all oranges.
    private static int solve(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int time = 0;
        Queue<Cell> queue = new LinkedList<>();
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++){
                if(grid[i][j] == 2)
                    queue.add(new Cell(i,j));
            }
        }
        queue.add(Cell.delimiter);

        while (!queue.isEmpty()){
            boolean changed = false;

            while (!queue.peek().isDelimiter()){
                Cell cell = queue.remove();
                int x = cell.x;
                int y = cell.y;

                // right cell
                if(isValid(r,c,x+1,y) && grid[x+1][y]==1){
                    if(!changed){
                        changed = true;
                        time++;
                    }
                    grid[x+1][y] = 2;
                    queue.add(new Cell(x+1,y));
                }

                // left cell
                if(isValid(r,c,x-1,y) && grid[x-1][y]==1){
                    if(!changed){
                        changed = true;
                        time++;
                    }
                    grid[x-1][y] = 2;
                    queue.add(new Cell(x-1,y));
                }

                // upper cell
                if(isValid(r,c,x,y-1) && grid[x][y-1]==1){
                    if(!changed){
                        changed = true;
                        time++;
                    }
                    grid[x][y-1] = 2;
                    queue.add(new Cell(x,y-1));
                }

                // lower cell
                if(isValid(r,c,x,y+1) && grid[x][y+1]==1){
                    if(!changed){
                        changed = true;
                        time++;
                    }
                    grid[x][y+1] = 2;
                    queue.add(new Cell(x,y+1));
                }
            }
            // remove delimiter
            queue.remove();

            if(!queue.isEmpty())
                queue.add(Cell.delimiter);
        }

        return freshLeft(grid) ? -1 : time;
    }

    private static boolean isValid(int r, int c , int i, int j){
        return (i>=0 && i<r && j>=0 && j<c);
    }

    private static boolean freshLeft(int[][] grid){
        for(int[] row : grid)
            for(int orange : row)
                if(orange == 1) return true;

        return false;
    }
}