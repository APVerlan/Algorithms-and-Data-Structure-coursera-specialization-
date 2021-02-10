#include <iostream>
#include <vector>

using std::vector;

long long merge_inversions(vector<int> &a, size_t left, size_t mid, size_t right){
	size_t i = left, j = mid, k = 0;
	vector<int> b(right - left);
	long long inversion_counter = 0;

	while (i < mid && j < right) {
		if (a[i] <= a[j]){
			b[k] = a[i];
			k++;
			i++;
		} else {
			b[k] = a[j];
			k++;
			j++;
			inversion_counter += mid - i;
		}
	}

	if (j <= right - 1) {
		while (j < right) {
			b[k] = a[j];
			k++;
			j++;
		}
	}

	if (i <= mid - 1) {
		while (i < mid) {
			b[k] = a[i];
			k++;
			i++;
		}
	}

	for (i = 0, j = left; i < b.size(); ++i, ++j) {
		a[j] = b[i];
	}

	return inversion_counter;

}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;

  if (right <= left + 1) 
		return number_of_inversions;

  size_t mid = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, mid);
  number_of_inversions += get_number_of_inversions(a, mid, right);
  
	//write your code here
	
	number_of_inversions += merge_inversions(a, left, mid, right);
	
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  
	std::cout << get_number_of_inversions(a, 0, a.size()) << '\n';
}
