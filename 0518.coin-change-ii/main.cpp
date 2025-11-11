#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int change1(int amount, vector<int>& coins) {
    vector<vector<size_t>> dp(coins.size() + 1, vector<size_t>(amount + 1, 0));

    for (auto& coin : dp) {
      coin[0] = 1;
    }

    for (int idx = 1; idx <= coins.size(); ++idx) {
      for (int sum = 0; sum <= amount; ++sum) {
        dp[idx][sum] = dp[idx - 1][sum];
        if (sum >= coins[idx - 1]) {
          dp[idx][sum] += dp[idx][sum - coins[idx - 1]];
        }
      }
    }

    return dp[coins.size()][amount];
  }

  int change(int amount, vector<int>& coins) {
    vector<size_t> dp(amount + 1, 0);

    dp[0] = 1;

    for (const auto coin : coins) {
      for (int sum = coin; sum <= amount; ++sum) {
        dp[sum] += dp[sum - coin];
      }
    }

    return dp[amount];
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  for (auto t = 0; t < tc; ++t) {
    int amount;
    cin >> amount;
    cin.ignore();

    string line;
    getline(cin, line);
    stringstream ss(line);

    int x;
    vector<int> coins;
    while (ss >> x) {
      coins.push_back(x);
    }

    auto sol = Solution();
    cout << sol.change(amount, coins) << endl;
  }

  return 0;
}
