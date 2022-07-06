#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> res;
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        // TODO
        for(string word : dictionary){
            if(exists(board, word))
                res.push_back(word);
        }
        return res;
    }

    bool exists(vector<vector<char>> &board, string word){
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0] and find(i,j,0,board,word,visited))
                    return true;
            }
        }
        return false;
    }

    bool find(int i, int j, int idx, vector<vector<char>> &board, string word, vector<vector<bool>> &visited){
        if(idx == word.length()) return true;

        visited[i][j] = true;

        int moves[8][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,1}, {-1,1}, {1,-1}};
        int m = board.size();
        int n = board[0].size();

        for(int k=0; k<8; k++){
            int next_i = i + moves[k][0];
            int next_j = j + moves[k][1];
            if(next_i>=0 and next_i<m and next_j>=0 and next_j<n and !visited[next_i][next_j] and board[i][j]==word[idx]){
                if(find(next_i, next_j, idx+1, board, word, visited))
                    return true;
            }
        }

        visited[i][j] = false;
        return false;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
