#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto& time : times) {
      adj[time[0]].emplace_back(time[2], time[1]);
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, k);

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();

      auto curr_dist = curr.first;
      auto curr_node = curr.second;

      if (curr_dist > dist[curr_node]) {
        continue;
      }

      for (auto& next : adj[curr_node]) {
        auto next_dist = curr_dist + next.first;
        if (next_dist < dist[next.second]) {
          dist[next.second] = next_dist;
          pq.emplace(next_dist, next.second);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (dist[i] == INT_MAX) return -1;
      ans = max(ans, dist[i]);
    }
    return ans;
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  string line;
  stringstream ss;

  for (int t = 0; t < tc; ++t) {
    int edges;
    cin >> edges;
    cin.ignore();

    vector<vector<int>> times(edges, vector<int>(3));
    for (int i = 0; i < edges; ++i) {
      cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    int n;
    cin >> n;

    int k;
    cin >> k;

    auto sol = Solution();
    cout << sol.networkDelayTime(times, n, k) << endl;
  }
}
