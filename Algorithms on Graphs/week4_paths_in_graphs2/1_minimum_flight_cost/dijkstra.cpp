#include <iostream>
#include <vector>
#include <queue>
#include <limits> 

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
	vector<int> dist(adj.size(), std::numeric_limits<int>::max());
	vector<bool> complited(adj.size());
	
	dist[s] = 0;

	auto compare = [](pair<int, int> lhs, 
			pair<int, int> rhs) {
	return lhs.second > rhs.second;
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> Q(compare);

	Q.push(std::make_pair(s, dist[s]));
	
	while (!Q.empty()) {
		int v = Q.top().first;
		Q.pop();
		
		if (!complited[v]) {
			for (int i = 0; i < adj[v].size(); i++) {
				if (dist[adj[v][i]] > dist[v] + cost[v][i]) {
					dist[adj[v][i]] = dist[v] + cost[v][i];
					complited[v] = true;
					Q.push(std::make_pair(adj[v][i], dist[adj[v][i]]));
				}
			}
		}


	}
	if (dist[t] == std::numeric_limits<int>::max())
		return -1;

  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
