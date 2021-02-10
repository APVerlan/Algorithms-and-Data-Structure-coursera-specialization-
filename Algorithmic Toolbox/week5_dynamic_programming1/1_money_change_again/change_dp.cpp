#include <iostream>
#include <vector>

using std::vector;

int get_change(int m) {
	vector<int> coins(m + 1, -1);
	coins[0] = 0;
	
	vector<int> change = {1, 3, 4};

	for (size_t i = 1; i < coins.size(); ++i) {
		for (int coin : change) {
			if (i >= coin) {
				int min_coin = coins[i - coin] + 1;

				if (min_coin < coins[i] || coins[i] == -1)
					coins[i] = min_coin;
			}
		}

	}

	return coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
