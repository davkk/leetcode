// Created by Dawid Karpiński at 2025/06/29 22:52
// leetgo: dev
// https://leetcode.com/problems/equal-row-and-column-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Entry {
  std::vector<int> key;
  int val;
};

using Bucket = std::vector<Entry>;

struct Map {
  int size {0};
  std::vector<Bucket> buckets;

  Map() {
    buckets.resize(16);
  }

  auto hash(std::vector<int>& key, int size) -> int {
    auto idx {0};
    for (auto item : key) {
      idx += item;
    }
    return idx % size;
  }

  auto hash(std::vector<int>& key) -> int {
    return hash(key, buckets.size());
  }

  auto find_entry(Bucket& bucket, std::vector<int>& key) -> Entry* {
    for (auto& entry : bucket) {
      if (entry.key == key) {
        return &entry;
      }
    }
    return nullptr;
  }

  auto set(std::vector<int> key, int val) {
    auto& bucket {buckets[hash(key)]};
    Entry* entry {find_entry(bucket, key)};
    if (entry) {
      entry->val = val;
    } else {
      bucket.push_back({key, val});
      ++size;
    }

    if (static_cast<float>(size) / buckets.size() >= 0.75) {
      resize();
    }
  }

  auto get(std::vector<int> key) -> Entry* {
    auto& bucket {buckets[hash(key)]};
    return find_entry(bucket, key);
  }

  auto resize() -> void {
    std::vector<Bucket> new_buckets(buckets.size() * 2);
    size = 0;

    for (auto& bucket : buckets) {
      for (auto& entry : bucket) {
        auto idx {hash(entry.key, new_buckets.size())};
        new_buckets[idx].emplace_back(std::move(entry));
        ++size;
      }
    }

    buckets = std::move(new_buckets);
  }
};

class Solution {
  public:
  int equalPairs(vector<vector<int>>& grid) {
    auto seen {Map {}};
    for (auto y {0}; y < grid.size(); ++y) {
      auto column {std::vector<int> {}};
      for (auto x {0}; x < grid[0].size(); ++x) {
        column.push_back(grid[x][y]);
      }
      if (auto entry {seen.get(column)}) {
        seen.set(column, ++entry->val);
      } else {
        seen.set(column, 1);
      }
    }

    auto pairs {0};
    for (auto& row : grid) {
      if (auto entry {seen.get(row)}) {
        pairs += entry->val;
      }
    }

    return pairs;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> grid;
  LeetCodeIO::scan(cin, grid);

  Solution* obj = new Solution();
  auto res = obj->equalPairs(grid);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
