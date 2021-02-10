#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

void max_sliding_window(vector<int> const & A, int w) {
	deque<int> relevant;
	
	for (int i = 0; i < w; ++i) {
		while (!relevant.empty() && A[i] > relevant.back()) {
			relevant.pop_back();
		}

		relevant.push_back(A[i]);
	}
	
	cout << relevant.front() << " ";

	for (int i = 1; i < A.size() - w + 1; ++i) {
		if (relevant.front() == A[i - 1])
			relevant.pop_front();
		
		while (!relevant.empty() && A[i + w - 1] > relevant.back()) {
			relevant.pop_back();
		}
		
		relevant.push_back(A[i + w - 1]);
		
		cout << relevant.front() << " ";
	}

	return;
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
