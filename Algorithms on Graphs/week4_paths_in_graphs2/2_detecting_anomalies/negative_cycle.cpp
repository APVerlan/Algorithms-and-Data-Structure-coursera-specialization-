#include <iostream>
#include <vector>
#include <limits>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	vector<long long> dist(adj.size(), std::numeric_limits<int>::max());

	dist[0] = 0;

	for (int j = 0; j < adj.size(); j++) {
		for (int i = 0; i < adj.size(); i++) {
			for (int k = 0; k < adj[i].size(); k++) {
				if (dist[adj[i][k]] > dist[i] + cost[i][k]) {
					if (j == adj.size() - 1)
						return 1;

					dist[adj[i][k]] = dist[i] + cost[i][k];
				}
			}
		}
	}

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
