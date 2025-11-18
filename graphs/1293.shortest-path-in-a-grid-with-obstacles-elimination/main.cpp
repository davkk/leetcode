#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    auto n = grid.size();
    auto m = grid[0].size();
    if (k >= m + n - 2) {
      return m + n - 2;
    }

    vector<vector<int>> best_k(n, vector<int>(m, -1));
    queue<tuple<int, int, int>> q;

    q.push({0, 0, k});
    best_k[0][0] = k;

    array<pair<int, int>, 4> dirs = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

    auto steps = 0;
    while (!q.empty()) {
      auto size = q.size();
      for (int i = 0; i < size; ++i) {
        auto curr = q.front();
        q.pop();

        auto curr_x = get<0>(curr);
        auto curr_y = get<1>(curr);
        auto curr_k = get<2>(curr);

        if (curr_x == n - 1 && curr_y == m - 1) {
          return steps;
        }

        for (auto& dir : dirs) {
          auto next_x = curr_x + dir.first;
          auto next_y = curr_y + dir.second;

          if (next_x < 0 or next_y < 0 or next_x >= n or next_y >= m) {
            continue;
          }

          auto next_k = curr_k - grid[next_x][next_y];
          if (next_k < 0 || next_k <= best_k[next_x][next_y]) {
            continue;
          }

          best_k[next_x][next_y] = next_k;
          q.push({next_x, next_y, next_k});
        }
      }
      steps++;
    }

    return -1;
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  for (int t = 0; t < tc; ++t) {
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> grid(n);

    for (auto i = 0; i < n; ++i) {
      string line;
      getline(cin, line);
      stringstream ss(line);
      int x;
      while (ss >> x) {
        grid[i].push_back(x);
      }
    }

    int k;
    cin >> k;
    cin.ignore();

    auto sol = Solution();
    cout << sol.shortestPath(grid, k) << endl;
  }
}
