#include <bits/stdc++.h>
using namespace std;

const vector<string> phone = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> solve(const string& digits) {
  auto curr = 0;
  std::vector<string> combs;

  function<void(string, int)> dfs = [&](string comb, int idx) {
    if (idx == digits.size()) {
      combs.push_back(comb);
      return;
    }

    for (const auto& cand : phone[digits[idx] - '0']) {
      comb.push_back(cand);
      dfs(comb, idx + 1);
      comb.pop_back();
    }
  };

  dfs("", 0);
  return combs;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string digits;
  while (cin >> digits) {
    auto res = solve(digits);
    for (const auto& comb : res) {
      cout << comb << " ";
    }
  }

  return 0;
}
