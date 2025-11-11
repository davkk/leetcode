#include <bits/stdc++.h>
using namespace std;

class SolutionRec {
  public:
  int rob(vector<int>& nums) {
    map<int, int> dp;
    function<int(int)> aux = [&](int i) {
      if (i < 0) {
        return 0;
      }
      if (dp.find(i) != dp.end()) {
        return dp[i];
      }
      auto result = max(aux(i - 2) + nums[i], aux(i - 1));
      dp[i] = result;
      return result;
    };
    return aux(nums.size() - 1);
  }
};

class SolutionIter {
  public:
  int rob(vector<int>& nums) {
    int a = 0;
    int b = nums[0];

    for (auto i = 1; i < nums.size(); ++i) {
      auto c = max(a + nums[i], b);
      a = b;
      b = c;
    }

    return b;
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
    cout << sol.rob(nums) << endl;
  }
  return 0;
}
