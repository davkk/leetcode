#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int numDistinctRec(string s, string t) {
    std::map<pair<int, int>, int> dp;
    function<int(int, int)> aux = [&](int i, int j) {
      if (i >= s.size() && j < t.size()) {
        return 0;
      }
      if (j >= t.size()) {
        return 1;
      }
      if (dp.find({i, j}) != dp.end()) {
        return dp[{i, j}];
      }
      auto ways = 0;
      if (s[i] == t[j]) {
        ways += aux(i + 1, j + 1);
      }
      auto result = aux(i + 1, j) + ways;
      dp[{i, j}] = result;
      return result;
    };
    return aux(0, 0);
  }

  int numDistinct(string s, string t) {
    vector<vector<double>> dp(s.size() + 1, vector<double>(t.size() + 1, 0));

    for (int i = 0; i <= s.size(); ++i) {
      dp[i][t.size()] = 1;
    }

    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = t.size() - 1; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j] + (s[i] == t[j] ? dp[i + 1][j + 1] : 0);
      }
    }

    return dp[0][0];
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  for (int i = 0; i < tc; ++i) {
    string s;
    getline(cin, s);
    string t;
    getline(cin, t);

    auto sol = Solution();
    cout << sol.numDistinct(s, t) << endl;
  }
}
