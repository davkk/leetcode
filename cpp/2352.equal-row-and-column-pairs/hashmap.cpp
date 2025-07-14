#include <cmath>
#include <print>
#include <vector>

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
      idx = idx * 31 + item;
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
      bucket.emplace_back(key, val);
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

  auto show() {
    for (auto i {0}; i < buckets.size(); ++i) {
      auto& bucket {buckets[i]};
      std::println("{}: ", i);
      for (auto& entry : bucket) {
        std::print(" ");
        for (auto item : entry.key) {
          std::print(" {}", item);
        }
        std::print(" -> {}", entry.val);
        std::println();
      }
    }
  }
};

int main() {
  Map map {};
  map.set({1, 2, 3}, 1);
  map.set({1, 2, 3}, 999);
  map.set({4, 5, 6}, 2);

  map.set({1}, 69);
  map.set({17}, 420);

  auto result = map.get({1, 2, 3});
  if (result) {
    std::println("Found: {}", result->val);
  } else {
    std::println("Not Found!");
  }

  for (int i = 0; i < 15; i++) {
    map.set({i}, i * 10);
    std::println("Items: {}, Buckets: {}", map.size, map.buckets.size());
  }

  map.show();
}
