#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

void bfs(vector<vector<int>>& adj, vector<int>& distances, int s) {
	distances[s] = 0;
	
	queue<int> Q;
	Q.push(s);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		
		for (auto v : adj[u]) {
			if (distances[v] == -1) {
				Q.push(v);
				distances[v] = distances[u] + 1;
			}
		}
	}
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
	vector<int> distances(adj.size(), -1);
	
	bfs(adj, distances, s);

  return distances[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
