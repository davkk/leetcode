#include <bits/stdc++.h>
using namespace std;

class SolutionRec {
  public:
  using ll = long long;

  ll maxAlternatingSum(vector<int>& nums) {
    map<pair<int, bool>, ll> dp;

    function<ll(int, bool)> aux = [&](int i, bool pos) {
      if (i >= nums.size()) {
        return 0LL;
      }

      if (dp.find({i, pos}) != dp.end()) {
        return dp[{i, pos}];
      }

      auto curr = (2 * pos - 1) * nums[i];
      auto result = max(curr + aux(i + 1, !pos), aux(i + 1, pos));

      dp[{i, pos}] = result;
      return result;
    };

    return aux(0, true);
  }
};

class SolutionIter {
  public:
  using ll = long long;

  ll maxAlternatingSum(vector<int>& nums) {
    ll pos = 0;
    ll neg = 0;

    for (ll i = nums.size() - 1; i >= 0; --i) {
      auto next_pos = max(neg + nums[i], pos);
      auto next_neg = max(pos - nums[i], neg);
      pos = next_pos;
      neg = next_neg;
    }

    return pos;
  }
};

int main() {
  for (string line; getline(cin, line);) {
    stringstream ss(line);
    vector<int> nums;
    int num;
    while (ss >> num) {
      nums.push_back(num);
    }

    // auto sol = SolutionRec();
    auto sol = SolutionIter();
    cout << sol.maxAlternatingSum(nums) << endl;
  }
  return 0;
}
