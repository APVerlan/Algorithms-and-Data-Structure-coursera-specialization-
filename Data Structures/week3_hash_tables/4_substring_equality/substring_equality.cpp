#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const long long multiplier_1 = 521;
const long long multiplier_2 = 263;
const long long prime_1 = 10000007;
const long long prime_2 = 10000009;

class Solver {
	private:
		string s;
		vector<long long> hash_substr_1;
		vector<long long> hash_substr_2;
		vector<long long> mults_1, mults_2;
	public:	
		Solver(string& s) : s(s) {	
			// initialization, precalculation
			hash_substr_1.resize(s.size() + 1);
			hash_substr_2.resize(s.size() + 1);
			mults_1.resize(s.size() + 1);
			mults_2.resize(s.size() + 1);

			hash_substr_1[0] = 0;
			hash_substr_2[0] = 0;
			mults_1[0] = 1;
			mults_2[0] = 1;

			for (int i = 1; i <= s.size(); ++i) {
				hash_substr_1[i] = (hash_substr_1[i - 1] * multiplier_1 + s[i - 1]) % prime_1;
				hash_substr_2[i] = (hash_substr_2[i - 1] * multiplier_2 + s[i - 1]) % prime_2;
				mults_1[i] = (multiplier_1 * mults_1[i - 1]) % prime_1;
				mults_2[i] = (multiplier_2 * mults_2[i - 1]) % prime_2;
			}

		}
		
		string ask(int left, int right, int len) {
			long long hash_11, hash_21, hash_12, hash_22;

			hash_11 = (hash_substr_1[left + len] - (mults_1[len] * hash_substr_1[left]) % prime_1 + prime_1) % prime_1;
			hash_12 = (hash_substr_1[right + len] - (mults_1[len] * hash_substr_1[right]) % prime_1 + prime_1) % prime_1;
			hash_21 = (hash_substr_2[left + len] - (mults_2[len] * hash_substr_2[left]) % prime_2 + prime_2) % prime_2;
			hash_22 = (hash_substr_2[right + len] - (mults_2[len] * hash_substr_2[right]) % prime_2 + prime_2) % prime_2;

			string str = ((hash_22 == hash_21) && (hash_12 == hash_11) ? "Yes\n" : "No\n");
			return str;
		}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << solver.ask(a, b, l);
	}
}
