// Created by Dawid Karpiński at 2025/06/29 12:35
// leetgo: dev
// https://leetcode.com/problems/removing-stars-from-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Node {
  char value {};
  shared_ptr<Node> prev {};
};

struct Stack {
  shared_ptr<Node> tail {};
  size_t size {};

  void push(char value) {
    auto newNode = make_shared<Node>();
    newNode->value = value;
    ++size;

    if (tail == nullptr) {
      tail = newNode;
      return;
    }

    newNode->prev = tail;
    tail = newNode;
  }

  char pop() {
    assert(size > 0);
    assert(tail != nullptr);

    --size;
    auto value {tail->value};

    if (size == 0) {
      tail = nullptr;
      return value;
    }

    auto tmp {tail};
    tail = tail->prev;

    return value;
  }
};

class Solution {
  public:
  string removeStars(string s) {
    Stack stack {};

    for (auto& ch : s) {
      if (ch == '*') {
        stack.pop();
        continue;
      }
      stack.push(ch);
    }

    string result {""};
    while (stack.size) {
      result += stack.pop();
    }
    reverse(result.begin(), result.end());

    return result;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string s;
  LeetCodeIO::scan(cin, s);

  Solution* obj = new Solution();
  auto res = obj->removeStars(s);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
