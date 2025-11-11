#include <bits/stdc++.h>

using namespace std;

map<int, int> dp;

int climbStairs(int n) {
  if (dp.find(n) != dp.end()) {
    return dp[n];
  }

  if (n <= 2) {
    return n;
  }

  auto x = climbStairs(n - 2);
  auto y = climbStairs(n - 1);
  auto result = x + y;

  cout << n << ": " << x << " + " << y << " = " << result << endl;

  dp[n] = result;
  return result;
}

int climbStairs2(int n) {
  if (n <= 2) {
    return n;
  }

  auto a = 1;
  auto b = 2;

  for (auto i = 3; i <= n; ++i) {
    auto c = a + b;
    a = b;
    b = c;
  }

  return b;
}

int main() {
  int n;
  while (cin >> n) {
    int ans = climbStairs(n);
    cout << ans << endl;
  }
  return 0;
}
