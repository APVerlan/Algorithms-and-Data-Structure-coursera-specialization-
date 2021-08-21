#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using std::vector;
using std::pair;

double euclidean_distance(pair<double, double> p1, pair<double, double> p2) {
	return std::sqrt( (p1.first - p2.first) * (p1.first - p2.first) + 
			(p1.second - p2.second) * (p1.second - p2.second) ); 
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
	vector<double> dist(x.size(), std::numeric_limits<double>::max());
	vector<bool> complited(x.size());
	
	int s = 0;
	dist[s] = 0;

	auto compare = [](pair<int, double> lhs,
		pair<int, double> rhs) {
	return lhs.second > rhs.second;
	};

	std::priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(compare)> Q(compare);

	Q.push(std::make_pair(s, dist[s]));

	while (!Q.empty()) {
		int v = Q.top().first;
		Q.pop();
	 
		if (!complited[v]) {
			for (int i = 0; i < x.size(); i++) {
				if (v != i) {
					double d = euclidean_distance(std::make_pair(x[v], y[v]), 
								std::make_pair(x[i], y[i]));
					if (!complited[i] && dist[i] > d) {
						dist[i] = d;
						Q.push(std::make_pair(i, dist[i]));
					}
				}
			}

			complited[v] = true;
		}
	}

	for (auto it: dist) {
		result += it;
	}

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}