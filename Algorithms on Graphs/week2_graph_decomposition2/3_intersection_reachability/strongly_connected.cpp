#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::pair;
using std::map;

int CLOCK = 0;

vector<vector<int>> reverse_graph(vector<vector<int>>& adj) {
	vector<vector<int>> reverse(adj.size());

	for (size_t i = 0; i < adj.size(); ++i) {
		for (auto e : adj[i]) {
			reverse[e].push_back(i);
		}
	}

	return reverse;
}

void explore(vector<vector<int> > &adj, unordered_set<int>& comp, vector<bool> &visited, int x) {
	visited[x] = true;
	comp.insert(x);

	for (size_t i = 0; i < adj[x].size(); ++i) {
		if (!visited[adj[x][i]])
			explore(adj, comp, visited, adj[x][i]);
	}
}


void dfs(vector<vector<int> > &adj, vector<bool> &visited, map<int, int> &posts, vector<int>& post, int x) {
	visited[x] = true;

	for (size_t i = 0; i < adj[x].size(); ++i) {
		if (!visited[adj[x][i]])
			dfs(adj, visited, posts, post, adj[x][i]);
	}

	posts[CLOCK] = x;
	post[x] = CLOCK++;
}     

int number_of_strongly_connected_components(vector<vector<int>>& adj) {
  int result = 0;
  //write your code here
	map<int, int> posts;
	vector<bool> visited(adj.size());
	unordered_set<int> dropped;
	vector<int> post(adj.size());

	for (size_t i = 0; i < adj.size(); ++i) {
		if (!visited[i])
			dfs(adj, visited, posts, post, i);
	}

	auto reversed = reverse_graph(adj);
	visited = vector<bool>(adj.size());

	while (!posts.empty()) {
		explore(reversed, dropped, visited, posts.rbegin()->second);

		for (auto drop : dropped) {
			posts.erase(post[drop]);
		}

		result++;
		dropped.clear();
	}


  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
