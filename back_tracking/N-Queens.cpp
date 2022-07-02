//
// Created by Acher on 2022/7/1.
//
#include "iostream"
#include "string"
#include <vector> 
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        this->n = n;
        backtrack(board, 0);
        return res.size();
    }

private:
    int n;
    vector<vector<string>> res;
    bool isValid(vector<string>& board, int row, int col) {
        // Check col conflicts
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check left top conflicts
        for (int i = row - 1, j = col - 1; (i >= 0 && j >= 0); i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check right top conflicts
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtrack(vector<string>& board, int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col)) {
                continue;
            }

            // Place one queen
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            // Undo place
            board[row][col] = '.';
        }
    }
};

int main()
{
    Solution sz;
    cout << sz.totalNQueens(5);
}





/*
作者：jyj407
        链接：https://leetcode.cn/problems/n-queens-ii/solution/52-nhuang-hou-ii-by-jyj407-3zsn/
来源：力扣（LeetCode）
*/