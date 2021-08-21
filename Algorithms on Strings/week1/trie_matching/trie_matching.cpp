#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string>& patterns) {
	trie t;
	// write your code here
	for (auto& pattern : patterns) {
		int curr = 0;
		pattern += '$';
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
/*
int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}*/
bool Chek(string&& text, trie& t) {
	int i = 0, curr = 0;

	while (true) {
		if (t[curr].empty() || t[curr].count('$')) return true;

		if (t[curr].count(text[i]) && text[i] != '\0') {
			curr = t[curr][text[i++]];
		} else return false;
	}
}

vector<int> solve (string& text, int n, vector<string>& patterns)
{
	vector<int> result;

	// write your code here
	trie t = build_trie(patterns);

	for (int i = 0; i < text.size(); i++) {
		if (Chek(text.substr(i), t))
			result.push_back(i);
	}
	return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector<string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector<int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
