#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using std::vector;
using std::pair;
using std::map;

int CLOCK = 0;

void dfs(vector<vector<int> > &adj, vector<bool> &visited, map<int, int> &posts, int x) {
  //write your code here
	visited[x] = true;

	for (size_t i = 0; i < adj[x].size(); ++i) {
		if (!visited[adj[x][i]])
			dfs(adj, visited, posts, adj[x][i]);
	}

	posts[CLOCK++] = x;
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> visited(adj.size());
  map<int, int> posts;
  //write your code here
	for (size_t i = 0; i < adj.size(); ++i) {
	  if (!visited[i])
			dfs(adj, visited, posts, i);
	}

	vector<int> order;

	for (auto p: posts) {
		order.push_back(p.second);	
	}

	std::reverse(order.begin(), order.end());

  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
