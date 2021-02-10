#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
  private:
		vector<int> stack;
		int max_counter = 0, _max;

  public:

    void Push(int value) {
				if (_max == value && !stack.empty()) {
					max_counter++;
				}

				if (stack.empty() || value > _max) {
					_max = value;
					max_counter = 1;
				}

        stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());

				if (stack[stack.size() - 1] == _max) {
					max_counter--;
				}

        stack.pop_back();

				if (max_counter == 0) {
					_max = *max_element(stack.begin(), stack.end());
					max_counter = 1;
				}
    }

    int Max() const {
        assert(stack.size());
        return _max;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
