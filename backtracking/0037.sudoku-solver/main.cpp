#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  using Board = vector<vector<char>>;

  bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == c) {
        return false;
      }
      if (board[i][col] == c) {
        return false;
      }
      if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
        return false;
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>>& board) {
    function<bool(int, int)> aux = [&](int row, int col) {
      if (row == 9) {
        return true;
      }
      if (col == 9) {
        return aux(row + 1, 0);
      }
      if (board[row][col] != '.') {
        return aux(row, col + 1);
      }
      for (char c = '1'; c <= '9'; ++c) {
        if (isValid(board, row, col, c)) {
          board[row][col] = c;
          if (aux(row, col + 1)) {
            return true;
          }
          board[row][col] = '.';
        }
      }
      return false;
    };
    aux(0, 0);
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  string line;

  vector<vector<char>> board(9, vector<char>(9, '.'));

  for (int t = 0; t < tc; ++t) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cin >> board[i][j];
      }
    }

    auto sol = Solution();
    sol.solveSudoku(board);

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cout << board[i][j];
        cout << " ";
      }
      cout << endl;
    }
  }
}
