#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int minDistanceRec(string word1, string word2) {
    map<pair<int, int>, int> dp;
    function<int(int, int)> aux = [&](int i, int j) {
      if (i == 0) {
        return j;
      }
      if (j == 0) {
        return i;
      }
      if (dp.find({i, j}) != dp.end()) {
        return dp[{i, j}];
      }
      if (word1[i - 1] == word2[j - 1]) {
        return aux(i - 1, j - 1);
      }
      auto result = 1 + min({aux(i - 1, j - 1), aux(i - 1, j), aux(i, j - 1)});
      dp[{i, j}] = result;
      return result;
    };
    return aux(word1.size(), word2.size());
  }

  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT_MAX));

    for (auto i = 0; i <= word1.size(); ++i) {
      dp[i][0] = i;
    }
    for (auto j = 0; j <= word2.size(); ++j) {
      dp[0][j] = j;
    }

    for (auto i = 1; i <= word1.size(); ++i) {
      for (auto j = 1; j <= word2.size(); ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
      }
    }

    return dp[word1.size()][word2.size()];
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  string line;
  stringstream ss;
  int x;

  for (int t = 0; t < tc; ++t) {
    string word1, word2;
    getline(cin, word1);
    getline(cin, word2);

    auto sol = Solution();
    cout << sol.minDistance(word1, word2) << endl;
  }
}
