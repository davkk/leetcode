#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    auto inf = INT_MAX;
    vector<int> dp(days.size() + 1, inf);
    auto duration = array<int, 3> {1, 7, 30};

    dp[days.size()] = 0;

    for (int i = days.size() - 1; i >= 0; --i) {
      for (int cost = 0; cost < costs.size(); ++cost) {
        auto j = i;
        while (j < days.size() && days[j] < days[i] + duration[cost]) {
          ++j;
        };
        dp[i] = min(dp[i], costs[cost] + dp[j]);
      }
    }

    return dp[0];
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
    vector<int> days;
    vector<int> costs;

    getline(cin, line);
    ss.str(line);
    ss.clear();
    while (ss >> x) {
      days.push_back(x);
    }
    getline(cin, line);
    ss.str(line);
    ss.clear();
    while (ss >> x) {
      costs.push_back(x);
    }

    auto sol = Solution();
    cout << sol.mincostTickets(days, costs) << endl;
  }
}
