#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int k, int n) {
  vector<vector<int>> combs;

  function<void(vector<int>, int, int, int)> aux = [&](vector<int> comb, int s, int k, int start) {
    if (k == 0) {
      if (s == 0) {
        combs.push_back(comb);
      }
      return;
    }

    for (int i = start; i <= 9; ++i) {
      if (i > s) break;
      comb.push_back(i);
      aux(comb, s - i, k - 1, i + 1);
      comb.pop_back();
    }
  };

  aux({}, n, k, 1);
  return combs;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k, n;
  while (cin >> k >> n) {
    auto res = solve(k, n);
    for (const auto& c : res) {
      for (const auto& x : c) {
        cout << x;
      }
      cout << " ";
    }
    cout << endl;
  }

  return 0;
}
