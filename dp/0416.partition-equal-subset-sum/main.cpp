#include <bits/stdc++.h>
using namespace std;

// basically a target sum problem

class SolutionRec {
  public:
  bool canPartition(vector<int>& nums) {
    map<pair<int, int>, bool> dp;

    auto t = 0;
    for (const auto num : nums) {
      t += num;
    }
    if (t % 2 > 0) {
      return false;
    }
    t /= 2;

    function<bool(int, int)> aux = [&](int s, int i) {
      if (i >= nums.size()) {
        return false;
      }
      if (s == 0) {
        return true;
      }
      if (s < 0) {
        return false;
      }

      if (dp.find({s, i}) != dp.end()) {
        return dp[{s, i}];
      }

      auto result = aux(s - nums[i], i + 1) || aux(s, i + 1);
      dp[{s, i}] = result;
      return result;
    };
    return aux(t, 0);
  }
};

class Solution {
  public:
  bool canPartition(vector<int>& nums) {
    auto t = 0;
    for (const auto num : nums) {
      t += num;
    }
    if (t % 2 > 0) {
      return false;
    }
    t /= 2;

    vector<bool> dp(t + 1, false);
    dp[0] = true;

    for (const auto num : nums) {
      for (auto s = t; s >= num; --s) {
        dp[s] = dp[s] || dp[s - num];
      }
    }

    return dp[dp.size() - 1];
  }
};

int main() {
  for (string line; getline(cin, line);) {
    stringstream ss(line);
    int num;
    vector<int> nums;
    while (ss >> num) {
      nums.push_back(num);
    }

    auto sol = Solution();
    cout << sol.canPartition(nums) << endl;
  }
  return 0;
}
