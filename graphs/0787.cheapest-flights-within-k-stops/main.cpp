#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto flight : flights) {
      adj[flight[0]].push_back({flight[2], flight[1]});
    }

    vector<int> dists(n, INT_MAX);
    queue<tuple<int, int, int>> pq;
    pq.push({0, 0, src});
    dists[src] = 0;

    while (!pq.empty()) {
      auto curr = pq.front();
      pq.pop();

      auto curr_dist = get<0>(curr);
      auto curr_stops = get<1>(curr);
      auto curr_idx = get<2>(curr);

      if (curr_stops > k) {
        continue;
      }

      for (auto nb : adj[curr_idx]) {
        auto nb_dist = nb.first;
        auto nb_idx = nb.second;

        auto new_dist = curr_dist + nb_dist;
        auto new_stops = curr_stops + 1;

        if (new_dist < dists[nb_idx]) {
          dists[nb_idx] = new_dist;
          pq.push({new_dist, new_stops, nb_idx});
        }
      }
    }

    return dists[dst] == INT_MAX ? -1 : dists[dst];
  }
};

int main() {
  int tc;
  cin >> tc;
  cin.ignore();

  for (int t = 0; t < tc; ++t) {
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> flights;

    int num_flights;
    cin >> num_flights;
    cin.ignore();

    for (int i = 0; i < num_flights; ++i) {
      int from, to, price;
      cin >> from >> to >> price;
      cin.ignore();
      flights.push_back({from, to, price});
    }

    int src, dst, k;
    cin >> src >> dst >> k;
    cin.ignore();

    auto sol = Solution();
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
  }
}
