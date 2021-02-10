#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool MaxString(string lhs, string rhs){
	
	int i = 0, j = 0;
	while(true){
		
		if (i >= lhs.size() && i >= rhs.size() && j > 0)
			i = 0;

		if (i >= lhs.size() && i >= rhs.size())
			break;

		if (i >= lhs.size()){
			if (j < rhs.size()){
				if (rhs[i] < rhs[j]){
					return true;
				} else if(rhs[i] > rhs[j]){
					return false;
				} else {
					++i;
					++j;
					continue;
				}
			} else break;
		}

		if (i >= rhs.size()){
			if (j < lhs.size()){
				if (lhs[i] < lhs[j]){
					return false;
				} else if (lhs[i] > lhs[j]) {
					return true;
				} else {
					++i;
					++j;
					continue;
				}
			} else break;
		}

		if (lhs[i] > rhs[i])
			return true;

		if (rhs[i] > lhs[i])
			return false;
		
		++i;
	}

	return false;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  
	std::sort(a.begin(), a.end(), MaxString);
	
	for (int i = 0; i < a.size(); ++i){
		ret << a[i];		
	}

  string result;
  ret >> result;
  return result;
}

int main() {
	
		int n;
		std::cin >> n;
		vector<string> a(n);
		for (size_t i = 0; i < a.size(); i++) {
			std::cin >> a[i];
		}
		std::cout << largest_number(a) << "\n";
	

	/*for (int i = 0; i < 1000000; ++i) {
		int a = rand() % 100;
		int b = rand() % 1000;

		string a_str = to_string(a);
		string b_str = to_string(b);

		if (largest_number({ a_str, b_str }) != largest_number({ b_str, a_str })) {
			cout << "FAIL " << a << " " << b << "\n";
			break;
		}
	}*/
	/*for (int i = 0; i < 1000000; ++i) {

		int n = rand() % 100;
		vector<string> a(n);

		for (int i = 0; i < n; ++i) {
			a[i] = to_string(rand() % 13);
		}

		auto m = largest_number(a);
	}*/
}
