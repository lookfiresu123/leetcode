#include <vector>
#include <string>

using namespace std;

// use dfs algorithm of graph
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if (board.empty() || board[0].empty() || word.empty())
            return false;
        int row = board.size(), col = board[0].size();
        for (int i = 0 ; i < row ; ++i)
            for (int j = 0 ; j < col ; ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char> > &board, string &word, int i, int j, int index) {
        if (word.length() == index)
            return true;
        int row = board.size(), col = board[0].size();
        if (i < 0 || j < 0 || i >= row || j >= col)
            return false;
        if (board[i][j] != '+' && board[i][j] == word[index]) {
            char c = board[i][j];
            board[i][j] = '+';
            bool res =  dfs(board, word, i-1, j, index+1) || dfs(board, word, i+1, j, index+1)
                || dfs(board, word, i, j-1, index+1) || dfs(board, word, i, j+1, index+1);
            board[i][j] = c;
            return res;
        }
        return false;
    }
};
