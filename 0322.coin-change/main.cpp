#include <bits/stdc++.h>
using namespace std;

class SolutionRec {
  public:
  int coinChange(vector<int>& coins, int amount) {
    map<tuple<int, int>, int> dp;
    function<int(int, int)> aux = [&](int idx, int remain) {
      if (remain == 0) {
        return 0;
      }
      if (remain < 0 || idx >= coins.size()) {
        return INT_MAX;
      }

      if (dp.find({idx, remain}) != dp.end()) {
        return dp[{idx, remain}];
      }

      auto take = aux(idx, remain - coins[idx]);
      auto skip = aux(idx + 1, remain);

      auto result = min(take + (take != INT_MAX), skip);

      dp[{idx, remain}] = result;
      return result;
    };
    auto result = aux(0, amount);
    return result == INT_MAX ? -1 : result;
  }
};

class Solution {
  public:
  int coinChange1(vector<int>& coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));

    for (auto& coin : dp) {
      coin[0] = 0;
    }

    for (int idx = coins.size() - 1; idx >= 0; --idx) {
      for (int sum = 0; sum <= amount; ++sum) {
        auto take = sum >= coins[idx] && dp[idx][sum - coins[idx]] != INT_MAX ? 1 + dp[idx][sum - coins[idx]] : INT_MAX;
        auto skip = idx + 1 <= coins.size() ? dp[idx + 1][sum] : INT_MAX;
        dp[idx][sum] = min(take, skip);
      }
    }

    auto result = dp[0][amount];
    return result == INT_MAX ? -1 : result;
  }

  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;

    for (int sum = 1; sum <= amount; ++sum) {
      for (const auto coin : coins) {
        if (sum >= coin) {
          dp[sum] = min(dp[sum], 1 + dp[sum - coin]);
        }
      }
    }

    auto result = dp[amount];
    return result == INT_MAX - 1 ? -1 : result;
  }
};

int main() {
  int i = 0;

  vector<int> coins;
  int amount;

  for (string line; getline(cin, line); ++i) {
    if (i % 2 == 0) {
      stringstream ss(line);
      int coin;
      coins.clear();
      while (ss >> coin) {
        coins.push_back(coin);
      }
    } else {
      amount = stoi(line);

      auto sol = Solution();
      cout << sol.coinChange(coins, amount) << endl;
    }
  }
  return 0;
}
