#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
	vector<vector<int>> weights(W + 1, vector<int> (w.size() + 1));

	for (size_t j = 1; j <= w.size(); j++) {
		for (size_t ww = 1; ww <= W; ww++) {
			if (ww < w[j - 1]) {
				weights[ww][j] = weights[ww][j - 1];
			} else {
				weights[ww][j] = std::max(weights[ww][j - 1], w[j - 1] + weights[ww - w[j - 1]][j - 1]);
			}
		}
	}

  return weights[W][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
