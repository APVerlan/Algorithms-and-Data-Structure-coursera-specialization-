#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(const int dist, const int tank, vector<int> & stops) {
    // write your code here
    int count = 0, start= 0, idx_stop = 0;
    int old_idx = -1;
    while(true){

       if (start + tank >= dist)
	  return count;

       for (; idx_stop < stops.size(); ++idx_stop){
	   if (stops[idx_stop] > start + tank){
	      idx_stop--;
	      break;
	   }
	   
	   if (idx_stop == stops.size() - 1)
	      break;
       }
       
       
       //std::cout << start << " " << idx_stop << "\n";
       
       if (old_idx == idx_stop)
	  return -1;
       else{
          start = stops[idx_stop];
          count++;
       }

       old_idx = idx_stop;
    }
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
