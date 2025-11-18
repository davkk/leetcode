#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int lengthOfLISRec(vector<int>& nums) {
    map<pair<int, int>, int> dp;
    function<int(int, int)> aux = [&](int curr, int prev) {
      if (curr == nums.size()) {
        return 0;
      }
      if (dp.find({curr, prev}) != dp.end()) {
        return dp[{curr, prev}];
      }
      auto skip = aux(curr + 1, prev);
      auto take = 0;
      if (prev == -1 || nums[curr] > nums[prev]) {
        take = 1 + aux(curr + 1, curr);
      }
      auto result = max(skip, take);
      dp[{curr, prev}] = result;
      return result;
    };
    return aux(0, -1);
  }

  int lengthOfLISIter(vector<int>& nums) {
    vector<int> dp(nums.size() + 1, 0);
    for (int curr = nums.size() - 1; curr >= 0; --curr) {
      for (int prev = curr; prev >= 0; --prev) {
        dp[prev] = max(dp[prev], prev == 0 || nums[curr] > nums[prev - 1] ? 1 + dp[curr + 1] : 0);
      }
    }
    return dp[0];
  }

  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    vector<int> dp(n, 1);
    int max_len = 1;
    for (int curr = 0; curr < n; ++curr) {
      for (int prev = 0; prev < curr; ++prev) {
        if (nums[prev] < nums[curr]) {
          dp[curr] = max(dp[curr], dp[prev] + 1);
        }
      }
      max_len = max(max_len, dp[curr]);
    }
    return max_len;
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  for (string line; getline(cin, line);) {
    stringstream ss(line);
    int x;
    vector<int> nums;
    while (ss >> x) {
      nums.push_back(x);
    }

    auto sol = Solution();
    cout << sol.lengthOfLIS(nums) << endl;
  }
}
