/*
    Tags:  Strings, Dynamic Programming
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LPS {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String s = read.readLine();
            String result = solve(s);
            System.out.println(result);
        }
    }

    private static String solve(String s){
        int n = s.length();
        int[][] matrix = new int[n][n];

        for(int length=1; length<=n; length++){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;

                if(i==j)
                    matrix[i][j] = 1;
                else if(s.charAt(i) == s.charAt(j))
                    matrix[i][j] = matrix[i+1][j-1] +2;
                else
                    matrix[i][j] = Math.max(matrix[i][j-1],matrix[i+1][j]);
            }
        }
        int palindromeLength = matrix[0][n-1];

        StringBuilder result = new StringBuilder();
        for(int i=0, j=n-1; matrix[i][j]!=0;){
            if(matrix[i][j] == matrix[i][j-1])
                j--;
            else if(matrix[i][j] == matrix[i+1][j])
                i++;
            else {
                result.append(s.charAt(j));
                i++;
                j--;
            }
        }

        for(int i=palindromeLength/2-1; i>=0; i--)
            result.append(result.charAt(i));

        return result.toString();
    }
}

/*

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 43

*/
