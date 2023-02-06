#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0
#define N 9


class Solution
{
public:
    //Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N]){
        // TODO
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){

                if(grid[i][j] == UNASSIGNED){

                    for(int c=1; c<=9; c++){
                        if(is_valid(grid, i, j, c)){
                            grid[i][j] = c;
                            if(SolveSudoku(grid)) return true;
                            grid[i][j] = UNASSIGNED;
                        }
                    }
                    return false;

                }

            }
        }

        return true;
    }

    // TODO
    bool is_valid(int grid[N][N], int row, int col, int c){
        for(int i=0; i<N; i++){
            if(grid[row][i] == c) return false;
            if(grid[i][col] == c) return false;
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }

    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]){
        // TODO
        for(int i=0; i < N; i++){
            for(int j=0; j < N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int grid[N][N];

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout<<endl;
    }

    return 0;
}
