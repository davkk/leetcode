#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  string longestPalindrome(string s) {
    string result = "";
    auto maxLen = 0;

    for (auto i = 0; i < s.size(); ++i) {
      auto p = i;
      auto q = i;
      while (p >= 0 && q < s.size() && s[p] == s[q]) {
        if (q - p + 1 > maxLen) {
          maxLen = q - p + 1;
          result = s.substr(p, maxLen);
        }
        p--;
        q++;
      }

      p = i;
      q = i + 1;
      while (p >= 0 && q < s.size() && s[p] == s[q]) {
        if (q - p + 1 > maxLen) {
          maxLen = q - p + 1;
          result = s.substr(p, maxLen);
        }
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
    cout << sol.longestPalindrome(line) << endl;
  }
}
