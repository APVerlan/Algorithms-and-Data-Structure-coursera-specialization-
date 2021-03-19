#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool DFS_cycle(vector<vector<int>>& adj, int vertex, int counter) {
	bool is_cycle = false;

	if (counter > adj.size())
		return true;

	for (size_t i = 0; i < adj[vertex].size(); i++) {
		is_cycle = DFS_cycle(adj, adj[vertex][i], 1 + counter);

		if (is_cycle)
			break;
	}

	return is_cycle;
}

int acyclic(vector<vector<int>> &adj) {

	bool is_cycle = false;

	for (size_t i = 0; i < adj.size(); ++i) {
		is_cycle = DFS_cycle(adj, i, 0);

		if (is_cycle)
			break;
	}

  return is_cycle;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
