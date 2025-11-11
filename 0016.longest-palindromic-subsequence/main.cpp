#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int longestPalindromeSubseqRec(string s) {
    map<pair<int, int>, int> m;
    function<int(int, int)> aux = [&](int i, int j) {
      if (i > j) {
        return 0;
      }
      if (i == j) {
        return 1;
      }
      if (s[i] == s[j]) {
        return 2 + aux(i + 1, j - 1);
      }
      if (m.find({i, j}) != m.end()) {
        return m[{i, j}];
      }
      auto result = max(aux(i + 1, j), aux(i, j - 1));
      m[{i, j}] = result;
      return result;
    };
    return aux(0, s.size() - 1);
  }

  int longestPalindromeSubseq(string s) {
    vector<int> dp_prev(s.size(), 0);
    vector<int> dp(s.size(), 0);

    for (int i = s.size() - 1; i >= 0; --i) {
      dp[i] = 1;
      for (int j = i + 1; j < s.size(); ++j) {
        dp[j] = s[i] == s[j] ? 2 + dp_prev[j - 1] : max(dp_prev[j], dp[j - 1]);
      }
      dp_prev = dp;
    }

    return dp_prev[s.size() - 1];
  }
};

int main() {
  for (string line; getline(cin, line);) {
    auto sol = Solution();
    cout << sol.longestPalindromeSubseq(line) << endl;
  }
}
