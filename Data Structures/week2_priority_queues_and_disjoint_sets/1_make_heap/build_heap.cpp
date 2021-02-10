#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }
	

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

	void SiftDown(size_t idx, vector<int>& data, vector<pair<int, int>>& swaps) {
		size_t max_idx = idx;
		size_t lch_idx = 2 * idx + 1, rch_idx = 2 * idx + 2;

		if (lch_idx < data.size() && data[lch_idx] < data[max_idx])
			max_idx = lch_idx;

		if (rch_idx < data.size() && data[rch_idx] < data[max_idx])
			max_idx = rch_idx;

		if (idx != max_idx) {
			swap(data[idx], data[max_idx]);
			swaps.push_back(make_pair(idx, max_idx));
			SiftDown(max_idx, data, swaps);
		}
	}

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /*for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }*/
		for (int i = data_.size() / 2 - 1; i >= 0; i--) {
			SiftDown(i, data_, swaps_);
		}

  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

void SiftDown(size_t idx, vector<int>& data, vector<pair<int, int>>& swaps) {
	size_t max_idx = idx;
	size_t lch_idx = 2 * idx + 1, rch_idx = 2 * idx + 2;

	if (lch_idx < data.size() && data[lch_idx] < data[max_idx])
		max_idx = lch_idx;

	if (rch_idx < data.size() && data[rch_idx] < data[max_idx])
		max_idx = rch_idx;

	if (idx != max_idx) {
		swap(data[idx], data[max_idx]);
		swaps.push_back(make_pair(idx, max_idx));
		SiftDown(max_idx, data, swaps);
	}
}

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
