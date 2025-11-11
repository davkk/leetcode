#include <bits/stdc++.h>
using namespace std;

class SolutionRec {
  public:
  int findTargetSumWays(vector<int>& nums, int target) {
    map<pair<int, int>, int> dp;
    function<int(int, int)> aux = [&](int sum, int idx) {
      if (idx == nums.size()) {
        return sum == target ? 1 : 0;
      }
      if (dp.find({sum, idx}) != dp.end()) {
        return dp[{sum, idx}];
      }
      auto result = aux(sum + nums[idx], idx + 1) + aux(sum - nums[idx], idx + 1);
      dp[{sum, idx}] = result;
      return result;
    };
    return aux(0, 0);
  }
};

class Solution {
  public:
  int findTargetSumWaysSlow(vector<int>& nums, int target) {
    auto total = accumulate(nums.begin(), nums.end(), 0);

    if (total < abs(target)) {
      return 0;
    }

    vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * total + 1, 0));

    dp[nums.size()][target + total] = 1;

    for (int idx = nums.size() - 1; idx >= 0; --idx) {
      for (int sum = -total; sum <= total; ++sum) {
        auto add_idx = sum + nums[idx];
        auto sub_idx = sum - nums[idx];

        auto ways = 0;
        if (add_idx >= -total && add_idx <= total) {
          ways += dp[idx + 1][add_idx + total];
        }
        if (sub_idx <= total && sub_idx >= -total) {
          ways += dp[idx + 1][sub_idx + total];
        }
        dp[idx][sum + total] = ways;
      }
    }

    return dp[0][total];
  }

  int findTargetSumWays(vector<int>& nums, int target) {
    auto total = accumulate(nums.begin(), nums.end(), 0);
    if ((total + target) % 2 != 0 || total < abs(target)) {
      return 0;
    }
    auto subset_sum = (total + target) / 2;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(subset_sum + 1, 0));

    if (nums[0] == 0) {
      dp[0][0] = 2;
    } else {
      dp[0][0] = 1;
    }

    if (nums[0] != 0 && nums[0] <= subset_sum) {
      dp[0][nums[0]] = 1;
    }

    for (int idx = 1; idx < nums.size(); ++idx) {
      for (int sum = 0; sum <= subset_sum; ++sum) {
        if (sum >= nums[idx]) {
          dp[idx][sum] = dp[idx - 1][sum - nums[idx]];
        }
        dp[idx][sum] += dp[idx - 1][sum];
      }
    }

    return dp[nums.size() - 1][subset_sum];
  }
};

int main() {
  int i = 0;

  vector<int> nums;
  int target;

  for (string line; getline(cin, line); ++i) {
    if (i % 2 == 0) {
      stringstream ss(line);
      int num;
      nums.clear();
      while (ss >> num) {
        nums.push_back(num);
      }
    } else {
      target = stoi(line);

      auto sol = Solution();
      cout << sol.findTargetSumWays(nums, target) << endl;
    }
  }
  return 0;
}
