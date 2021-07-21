/*
https://www.geeksforgeeks.org/printing-longest-common-subsequence/
Tags:  Strings, Dynamic Programming
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LCS {

    public static void main (String[] args)throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t-->0)
        {
            String str = br.readLine();
            String s1 = str.split(" ")[0];
            String s2 = str.split(" ")[1];

            System.out.println(solve(s1,s2));
        }
    }

    private static String solve(String s1, String s2){
        int n = s1.length();
        int m = s2.length();
        int[][] matrix = new int[n+1][m+1];

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0)
                    matrix[i][j] = 0;
                else if(s1.charAt(i-1) == s2.charAt(j-1))
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                else
                    matrix[i][j] = Math.max(matrix[i][j-1],matrix[i-1][j]);
            }
        }

        StringBuilder result = new StringBuilder();
        for(int i=n,j=m; i>0 && j>0; ){
            if(matrix[i][j] == matrix[i-1][j])
                i--;
            else if(matrix[i][j] == matrix[i][j-1])
                j--;
            else{
                result.append(s1.charAt(i-1));
                i--; j--;
            }
        }

        return result.reverse().toString();
    }
}
