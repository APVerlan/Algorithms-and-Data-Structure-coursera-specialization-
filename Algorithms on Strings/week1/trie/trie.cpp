#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  for (auto& pattern : patterns) {
	  int curr = 0;
	  t.push_back(edges());
	  for (char s : pattern) {
		  if (t[curr].count(s)) {
			  curr = t[curr][s];
		  }
		  else {
			  t[curr][s] = t.size();
			  curr = t.size();
			  t.push_back(edges());
		  }
	  }
  }

  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}