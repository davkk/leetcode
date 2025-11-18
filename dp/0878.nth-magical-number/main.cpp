#include <bits/stdc++.h>

using namespace std;

using u64 = uint64_t;

u64 k = 1e9 + 7;

u64 gcd(u64 a, u64 b) {
  while (b != 0) {
    auto tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

u64 solve(u64 n, u64 a, u64 b) {
  auto lcm = a * b / gcd(a, b);

  auto lo = min(a, b);
  auto hi = n * lo;

  while (lo < hi) {
    auto x = lo + (hi - lo) / 2;

    if (x / a + x / b - x / lcm >= n) {
      hi = x;
    } else {
      lo = x + 1;
    }
  }

  return lo % k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  u64 n, a, b;
  while (cin >> n >> a >> b) {
    cout << solve(n, a, b) << endl;
  }

  return 0;
}
