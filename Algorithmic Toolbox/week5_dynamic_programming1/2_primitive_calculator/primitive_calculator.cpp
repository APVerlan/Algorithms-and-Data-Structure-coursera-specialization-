#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
	vector<int> num_iter(n + 1, -1);
	num_iter[1] = 0;

	vector<int> sequence;

	for (size_t i = 1; i < num_iter.size(); ++i) {
		for (auto op: {"+", "2", "3"}) {
			int min_iter;

			if (op == "+") {
				if (i >= 1) {
					min_iter = num_iter[i - 1] + 1;
					if (num_iter[i] > min_iter || num_iter[i] == -1)
						num_iter[i] = min_iter;
				}
			}

			if (op == "2") {
				if (i % 2 == 0) {
					min_iter = num_iter[i / 2] + 1;
					if (num_iter[i] > min_iter)
						num_iter[i] = min_iter;
				}
			}

			if (op == "3") {
				if (i % 3 == 0) {
					min_iter = num_iter[i / 3] + 1;
					if (num_iter[i] > min_iter)
						num_iter[i] = min_iter;
				}
			}

		}
	}
	
	sequence.push_back(n);

	int k = n;
	while (true) {
		int idx_min = k - 1, iter_min = num_iter[k - 1];

		if (k == 1) {
			break;
		}

		if (k % 2 == 0 && num_iter[k / 2] < iter_min) {
			idx_min = k / 2;
			iter_min = num_iter[k / 2];
		}
	
		if (k % 3 == 0 && num_iter[k / 3] < iter_min) {
			idx_min = k / 3;
			iter_min = num_iter[k / 3];
		}

		sequence.push_back(idx_min);
		k = idx_min;
	}

	std::reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
