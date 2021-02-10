#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

long long hash(const string& str) {
  long long result = 0;
  static const long long multiplier = 263;
  static const long long prime = 1000000007;
  for (int i = static_cast<int> (str.size()) - 1; i >= 0; --i) {
      result = (result * multiplier + str[i]) % prime; 
	}
	
	return result;
}

std::vector<long long> precomputehash(const string& text, size_t len) {
  static const long long multiplier = 263;
  static const long long prime = 1000000007;
	
	long long y =  1;
	long long max = LLONG_MAX, min = LLONG_MIN;

	for (size_t i = 0; i < len; ++i) {
		y = (y * multiplier) % prime;
	}

	std::vector<long long> hashes(text.size() - len + 1);
	hashes[text.size() - len] = hash(text.substr(text.size() - len, len)); 

	for (long long i = text.size() - len - 1; i >= 0; --i) {
		
		long long k = hashes[i + 1];
		for (size_t j = 1; j < multiplier; ++j) {
			k = (k + hashes[i + 1]) % prime;
		}

		long long k1 = y;
		for (size_t j = 1; j < text[i + len]; ++j) {
			k1 = (k1 + y) % prime;
		}

		long long v = k - k1 + text[i];
		if (v < 0)
			v = v + (1 + std::abs(k - k1) / prime) * prime;
		
		hashes[i] = (v) % prime;
	}

	return hashes; 
}

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
		size_t size = s.size();
		auto hashes = precomputehash(t, size);
		long long hash_value = hash(s);

		for (size_t i = 0; i + size <= t.size(); ++i) {
			if (hashes[i] == hash_value)
				if (t.substr(i, s.size()) == s)  
					ans.push_back(i);
		}
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
