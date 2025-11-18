#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int countSubstrings(string s) {
    auto result = 0;

    for (auto i = 0; i < s.size(); ++i) {
      auto p = i;
      auto q = i;
      while (p >= 0 && q < s.size() && s[p] == s[q]) {
        result++;
        p--;
        q++;
      }

      p = i;
      q = i + 1;
      while (p >= 0 && q < s.size() && s[p] == s[q]) {
        result++;
        p--;
        q++;
      }
    }

    return result;
  }
};

int main() {
  for (string line; getline(cin, line);) {
    auto sol = Solution();
    cout << sol.countSubstrings(line) << endl;
  }
}
