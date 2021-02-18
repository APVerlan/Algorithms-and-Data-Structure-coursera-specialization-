#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool in_order_(int i, vector<int>& res, const vector<Node>& tree, bool flag=false) {
		if (tree[i].left > 0) { 
			if (!in_order_(tree[i].left, res, tree))
				return false;
		}
		else flag = true;

		if (!res.empty() && flag && res.back() == tree[i].key) 
			res.push_back(tree[i].key);
		else if (!res.empty() && res.back() >= tree[i].key)
			return false;
		else 
			res.push_back(tree[i].key);

		if (tree[i].right > 0)
			if (!in_order_(tree[i].right, res, tree))
				return false;

		return true;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
	  if (tree.empty())
			return true;

		vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
		if (tree[0].left > 0)
			if (!in_order_(tree[0].left, result, tree))
				return false;
		if (!result.empty() && result.back() >= tree[0].key)
			return false;
		else result.push_back(tree[0].key);

		if (tree[0].right > 0)
			if (!in_order_(tree[0].right, result, tree))
				return false;

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
