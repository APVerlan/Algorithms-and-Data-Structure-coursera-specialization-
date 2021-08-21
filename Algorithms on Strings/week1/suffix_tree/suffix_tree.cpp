#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie ComputeSuffixTreeEdges(string& text) {
	trie t;
	// write your code here
	for (int i = 0; i < text.size(); i++) {
		int curr = 0;
		t.push_back(edges());
		for (char s : text.substr(i)) {
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
  string text;
  cin >> text;
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}
