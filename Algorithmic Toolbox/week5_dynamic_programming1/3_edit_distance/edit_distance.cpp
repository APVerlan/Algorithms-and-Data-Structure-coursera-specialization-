#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::vector;
using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
	
	vector<vector<int>> D(str1.size() + 1, vector<int>(str2.size() + 1));
	for (size_t i = 0; i <= str1.size(); ++i) {
		D[i][0] = i;
	}

	for (size_t i = 0; i <= str2.size(); ++i) {
		D[0][i] = i;
	}

	for (size_t i = 1; i <= str1.size(); ++i) {
		for (size_t j = 1; j <= str2.size(); ++j) {
			int min = D[i - 1][j] + 1;

			if (min > D[i][j - 1] + 1)
				min = D[i][j - 1] + 1;

			if (str1[i - 1] == str2[j - 1]){
				if (min > D[i - 1][j - 1])
					min = D[i - 1][j - 1];
			} else {
				if (min > D[i - 1][j - 1] + 1)
					min = D[i - 1][j - 1] + 1;
			}
			
			D[i][j] = min;
		}

	}

  return D[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
