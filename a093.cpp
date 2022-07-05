#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<vector<int>> res;

    vector<vector<int>> nQueen(int n) {
        // TODO
        vector<int> ans;
        vector<int> left_row(n,0);
        vector<int> upper_dia(2*n-1,0);
        vector<int> lower_dia(2*n-1, 0);
        nQueen(0, ans, left_row, upper_dia, lower_dia, n);
        return res;
    }

    void nQueen(int col, vector<int> &ans, vector<int> &left_row, vector<int> &upper_dia,vector<int> &lower_dia,int n){
        if(col == n){
            res.push_back(ans);
            return;
        }

        for(int row=0; row<n; row++){
            // is_safe
            if(!left_row[row] and !lower_dia[row+col] and !upper_dia[n-1 + row-col]){
                // place_queen
                ans.push_back(row+1);
                left_row[row] = 1;
                lower_dia[row+col] = 1;
                upper_dia[n-1 + row-col] = 1;

                nQueen(col+1, ans, left_row, upper_dia, lower_dia, n);

                // backtrack
                ans.pop_back();
                left_row[row] = 0;
                lower_dia[row+col] = 0;
                upper_dia[n-1 + row-col] = 0;
            }
        }
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u: ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}