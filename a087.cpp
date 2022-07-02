#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int new_color) {
        // TODO
        int initial_color = image[i][j];
        floodFill(image, i, j, initial_color, new_color);
        return image;
    }

    // TODO
    void floodFill(vector<vector<int>>& image, int i, int j, int initial_color, int new_color){
        if(i<0 or i>=image.size()) return;
        if(j<0 or j>=image[0].size()) return;
        if(image[i][j] != initial_color) return;
        if(image[i][j] == new_color) return;

        image[i][j] = new_color;
        floodFill(image, i+1, j, initial_color, new_color);
        floodFill(image, i-1, j, initial_color, new_color);
        floodFill(image, i, j+1, initial_color, new_color);
        floodFill(image, i, j-1, initial_color, new_color);
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i: ans) {
            for (auto j: i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}