#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::vector;
using std::string;
using std::max_element;
using std::min_element;
using std::pair;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

pair<vector<long long>, vector<char>> parser(const string& str) {
	long long n;
	char c;
	vector<char> chars;
	vector<long long> ints;

	std::stringstream stream(str); 
	
	stream >> n;
	ints.push_back(n);
	while(stream >> c) {
		stream >> n;
		ints.push_back(n);	
		chars.push_back(c);
	}

	return std::make_pair(ints, chars);
}

long long get_maximum_value(const string &exp) {
  //write your code here
	pair<vector<long long>, vector<char>> p = parser(exp);
	vector<long long> nums = p.first;
	vector<char> ops = p.second;

	vector<vector<long long>> T(nums.size(), vector<long long>(nums.size()));
	
	for (size_t i = 0; i < nums.size(); ++i) {
		T[i][i] = nums[i];
	}

	for (size_t delta = 1; delta < nums.size(); ++delta) {
		for (size_t i = 0, j = delta; i < nums.size() && j < nums.size(); i++, j++) {
			
			long long max_e, min_e;
			bool flag = true;
			for (size_t k = i; k < j; k++) {
				
				vector<long long> h = {eval(T[i][k], T[k + 1][j], ops[k]), eval(T[i][k], T[j][k + 1], ops[k]),
						eval(T[k][i], T[k + 1][j], ops[k]), eval(T[k][i], T[j][k + 1], ops[k])};
				
				if (flag) {
					max_e = *max_element(h.begin(), h.end());
					min_e = *min_element(h.begin(), h.end());
				}


				if (max_e < *max_element(h.begin(), h.end()))
					max_e = *max_element(h.begin(), h.end());

				if (min_e > * min_element(h.begin(), h.end()))
					min_e = *min_element(h.begin(), h.end());

				flag = false;
			}

			T[i][j] = max_e;
			T[j][i] = min_e;
		}
	}

  return T[0][nums.size() - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
