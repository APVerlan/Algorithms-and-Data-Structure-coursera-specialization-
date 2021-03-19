#include <iostream>
#include <vector>

void swap_pointers(int* p1, int* p2) {
	int* copy_p = p1;
	p1 = p2;
	p2 = copy_p;
}

void swap_min(int* m[], unsigned rows, unsigned cols) {
	int row = 0, min = m[0][0];

	for (unsigned i = 0; i < rows; ++i) {
		for (unsigned j = 0; j < cols; ++j) {
			if (min > m[i][j]) {
				min = m[i][j];
				row = i;
			}
		}
	}

	swap_pointers(m[0], m[row]);
}

int main() {
	const unsigned rows = 5;
	const unsigned cols = 3;
	int* m[rows] = {};
	int tmp[][cols] = { {1,2,3},{1,2,2},{1,2,0},{1,2,4},{1,2,5} };
	for (unsigned i = 0; i < rows; ++i) {
		m[i] = new int[cols];
		for (unsigned j = 0; j < cols; ++j)
			m[i][j] = tmp[i][j];
	}

	swap_min(m, rows, cols);

	for (unsigned i = 0; i < rows; ++i) {
		for (unsigned j = 0; j < cols; ++j)
			std::cout << m[i][j];
		std::cout << "\n";
	}
	return 0;
}
