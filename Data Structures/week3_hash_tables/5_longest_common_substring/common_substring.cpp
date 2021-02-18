#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Answer {
	size_t i, j, len;
	
	bool operator==(Answer rhs) { return (i == rhs.i && j == rhs.j && len == rhs.len); };
};

class HashString {
	public:

	vector<long long> ksubstr_hash1_, ksubstr_hash2_;

	HashString(string s) : str_(s) {
	precompute_hash_(s);
	};
	
	size_t size() const { return str_.size(); };

	void compute_substr_hash(size_t substr_size_) {
		ksubstr_hash1_.resize(str_.size() - substr_size_ + 1);
		ksubstr_hash2_.resize(str_.size() - substr_size_ + 1);

		for (size_t i = 0; i <= str_.size() - substr_size_; ++i) {
			ksubstr_hash1_[i] = (hash1_[i + substr_size_] - (mults_1[substr_size_] * hash1_[i]) % prime_1 + prime_1) % prime_1;
			ksubstr_hash2_[i] = (hash2_[i + substr_size_] - (mults_2[substr_size_] * hash2_[i]) % prime_2 + prime_2) % prime_2;
		}
	};

	private:

		const long long multiplier_1 =521;
		const long long multiplier_2 =263;
		const long long prime_1 =10000007;
		const long long prime_2 = 10000009;

		const string str_;
		vector<long long> hash1_, hash2_;
		vector<long long> mults_1, mults_2;

		void precompute_hash_(const string& s) {
			hash1_.resize(s.size() + 1);
			hash2_.resize(s.size() + 1);
			mults_1.resize(s.size() + 1);
			mults_2.resize(s.size() + 1);

			hash1_[0] = 0;
			hash2_[0] = 0;
			mults_1[0] = 1;
			mults_2[0] = 1;

			for (int i = 1; i <= s.size(); ++i) {
				hash1_[i] = (hash1_[i - 1] * multiplier_1 + s[i - 1]) % prime_1;
				hash2_[i] = (hash2_[i - 1] * multiplier_2 + s[i - 1]) % prime_2;
				mults_1[i] = (multiplier_1 * mults_1[i - 1]) % prime_1;
				mults_2[i] = (multiplier_2 * mults_2[i - 1]) % prime_2;
			}    
		}
};

Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	for (size_t i = 0; i < s.size(); i++)
		for (size_t j = 0; j < t.size(); j++)
			for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
				if (len > ans.len && s.substr(i, len) == t.substr(j, len))
					ans = {i, j, len};
	return ans;
}

Answer BinarySearch(HashString& str_1, HashString& str_2, size_t left, size_t right, Answer ans = {0, 0, 0}) {
	if (right - left < 1)
		return ans;

	Answer old = ans;

	size_t mid = left + (right - left) / 2;
	str_1.compute_substr_hash(mid);
	str_2.compute_substr_hash(mid);

	unordered_map<long long, pair<long long, size_t>> hash_table;
	for (size_t i = 0; i < str_1.ksubstr_hash1_.size(); ++i) {
		hash_table[str_1.ksubstr_hash1_[i]] = make_pair(str_1.ksubstr_hash2_[i], i);
	}
	
	for (size_t i = 0; i < str_2.ksubstr_hash1_.size(); ++i) {
		if(hash_table.count(str_2.ksubstr_hash1_[i]) > 0)
			if (hash_table[str_2.ksubstr_hash1_[i]].first == str_2.ksubstr_hash2_[i])
				ans = {hash_table[str_2.ksubstr_hash1_[i]].second, i, mid};
	}
	
	if (old == ans)
		return BinarySearch(str_1, str_2, left, mid, ans);
	else
		return BinarySearch(str_1, str_2, mid + 1, right, ans);
}

Answer solver_fast(const string& s, const string& t) {
	size_t k = min(s.size(), t.size());
	HashString str1{s}, str2{t};
	return BinarySearch(str1, str2, 0, k + 1);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solver_fast(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
